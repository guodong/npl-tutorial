/*
 * $Copyright: (c) 2018 Broadcom Corp.
 * All Rights Reserved.$
 * File:     bm_tbl_if.c
 * Purpose:  Behavior Model table interface source
 *
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated
 * Edits to this file will be lost when it is regenerated.
 *
 */

#include "include_libs.h"
#include "bm_field.h"
#include "bm_tbl_if.h"
#include "bm_main.h"

/* load table entry pointers */
vlan_table_entry_t *vlan_table_loc_entry = NULL;
sfc_mmu_profile_entry_t *sfc_mmu_profile_loc_entry = NULL;
sfc_edb_profile_entry_t *sfc_edb_profile_loc_entry = NULL;
sfc_iarb_profile_entry_t *sfc_iarb_profile_loc_entry = NULL;
/* load struct entry pointers */

/* debug flag */
int debug_en = 0;


void bm_pt_init(void)
{
}

void bm_pt_free(void)
{
}

int bm_pt_read(int unit, bm_sid_t sid,
               bm_pt_dyn_info_t *dyn_info, void *ovrr_info,
               uint32_t *data, size_t wsize)
{
    uint32_t field;
    uint64_t ref_value;
    _64bits ref_addr;
    _1bit index1;
    _12bits index12;
    int typ, status;

    assert(data);
    typ = *(int *) ovrr_info;
    status = 0;

    switch (sid) {

        case VLAN_TABLEm:
            if (bm_obj->vlan_table->max_entries > (uint) dyn_info->index) {
                index12 = dyn_info->index;
                vlan_table_loc_entry = bm_obj->vlan_table->read_entry(&index12);
#ifndef NO_CONSOLE_OUTPUT
                if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
                    vlan_table_loc_entry->print();
                }
#endif
                vlan_table_loc_entry->pack_data(data);
            } else {
                if (bm_obj->vlan_table->max_entries != (uint) dyn_info->index) {
#ifndef NO_CONSOLE_OUTPUT
                    bmi_log->error("ERROR: %s(): Table vlan_table, invalid index (%d)", __FUNCTION__, (uint) dyn_info->index);
#endif
                    return 1;
                } else if (typ == 3) {
                    vlan_table_loc_entry = new vlan_table_entry_t;
                    vlan_table_loc_entry->unpack_data(data);
                    status = bm_obj->vlan_table->lookup_entry(&vlan_table_loc_entry);
#ifndef NO_CONSOLE_OUTPUT
                    if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
                        vlan_table_loc_entry->print();
                    }
#endif
                    vlan_table_loc_entry->pack_data(data);
                    delete(vlan_table_loc_entry);
                } else {
#ifndef NO_CONSOLE_OUTPUT
                    bmi_log->error("ERROR: %s(): Table vlan_table, invalid operation (%d)", __FUNCTION__, typ);
#endif
                    return 1;
                }
            }
            break;

        case SFC_MMU_PROFILEm:
            if (bm_obj->sfc_mmu_profile->max_entries > (uint) dyn_info->index) {
                index1 = dyn_info->index;
                sfc_mmu_profile_loc_entry = bm_obj->sfc_mmu_profile->read_entry(&index1);
#ifndef NO_CONSOLE_OUTPUT
                if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
                    sfc_mmu_profile_loc_entry->print();
                }
#endif
                sfc_mmu_profile_loc_entry->pack_data(data);
            } else {
                if (bm_obj->sfc_mmu_profile->max_entries != (uint) dyn_info->index) {
#ifndef NO_CONSOLE_OUTPUT
                    bmi_log->error("ERROR: %s(): Table sfc_mmu_profile, invalid index (%d)", __FUNCTION__, (uint) dyn_info->index);
#endif
                    return 1;
                } else if (typ == 3) {
                    sfc_mmu_profile_loc_entry = new sfc_mmu_profile_entry_t;
                    sfc_mmu_profile_loc_entry->unpack_data(data);
                    status = bm_obj->sfc_mmu_profile->lookup_entry(&sfc_mmu_profile_loc_entry);
#ifndef NO_CONSOLE_OUTPUT
                    if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
                        sfc_mmu_profile_loc_entry->print();
                    }
#endif
                    sfc_mmu_profile_loc_entry->pack_data(data);
                    delete(sfc_mmu_profile_loc_entry);
                } else {
#ifndef NO_CONSOLE_OUTPUT
                    bmi_log->error("ERROR: %s(): Table sfc_mmu_profile, invalid operation (%d)", __FUNCTION__, typ);
#endif
                    return 1;
                }
            }
            break;

        case SFC_EDB_PROFILEm:
            if (bm_obj->sfc_edb_profile->max_entries > (uint) dyn_info->index) {
                index1 = dyn_info->index;
                sfc_edb_profile_loc_entry = bm_obj->sfc_edb_profile->read_entry(&index1);
#ifndef NO_CONSOLE_OUTPUT
                if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
                    sfc_edb_profile_loc_entry->print();
                }
#endif
                sfc_edb_profile_loc_entry->pack_data(data);
            } else {
                if (bm_obj->sfc_edb_profile->max_entries != (uint) dyn_info->index) {
#ifndef NO_CONSOLE_OUTPUT
                    bmi_log->error("ERROR: %s(): Table sfc_edb_profile, invalid index (%d)", __FUNCTION__, (uint) dyn_info->index);
#endif
                    return 1;
                } else if (typ == 3) {
                    sfc_edb_profile_loc_entry = new sfc_edb_profile_entry_t;
                    sfc_edb_profile_loc_entry->unpack_data(data);
                    status = bm_obj->sfc_edb_profile->lookup_entry(&sfc_edb_profile_loc_entry);
#ifndef NO_CONSOLE_OUTPUT
                    if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
                        sfc_edb_profile_loc_entry->print();
                    }
#endif
                    sfc_edb_profile_loc_entry->pack_data(data);
                    delete(sfc_edb_profile_loc_entry);
                } else {
#ifndef NO_CONSOLE_OUTPUT
                    bmi_log->error("ERROR: %s(): Table sfc_edb_profile, invalid operation (%d)", __FUNCTION__, typ);
#endif
                    return 1;
                }
            }
            break;

        case SFC_IARB_PROFILEm:
            if (bm_obj->sfc_iarb_profile->max_entries > (uint) dyn_info->index) {
                index1 = dyn_info->index;
                sfc_iarb_profile_loc_entry = bm_obj->sfc_iarb_profile->read_entry(&index1);
#ifndef NO_CONSOLE_OUTPUT
                if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
                    sfc_iarb_profile_loc_entry->print();
                }
#endif
                sfc_iarb_profile_loc_entry->pack_data(data);
            } else {
                if (bm_obj->sfc_iarb_profile->max_entries != (uint) dyn_info->index) {
#ifndef NO_CONSOLE_OUTPUT
                    bmi_log->error("ERROR: %s(): Table sfc_iarb_profile, invalid index (%d)", __FUNCTION__, (uint) dyn_info->index);
#endif
                    return 1;
                } else if (typ == 3) {
                    sfc_iarb_profile_loc_entry = new sfc_iarb_profile_entry_t;
                    sfc_iarb_profile_loc_entry->unpack_data(data);
                    status = bm_obj->sfc_iarb_profile->lookup_entry(&sfc_iarb_profile_loc_entry);
#ifndef NO_CONSOLE_OUTPUT
                    if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
                        sfc_iarb_profile_loc_entry->print();
                    }
#endif
                    sfc_iarb_profile_loc_entry->pack_data(data);
                    delete(sfc_iarb_profile_loc_entry);
                } else {
#ifndef NO_CONSOLE_OUTPUT
                    bmi_log->error("ERROR: %s(): Table sfc_iarb_profile, invalid operation (%d)", __FUNCTION__, typ);
#endif
                    return 1;
                }
            }
            break;

        default:
#ifndef NO_CONSOLE_OUTPUT
            bmi_log->error("ERROR: %s() Unknown table sid: 0x%x", __FUNCTION__, sid);
#endif
            break;
    }

    return status;
}

int bm_pt_write(int unit, bm_sid_t sid,
                bm_pt_dyn_info_t *dyn_info, void *ovrr_info,
                uint32_t *data)
{
    uint32_t field;
    uint64_t ref_value;
    _64bits ref_addr;
    _1bit index1;
    _12bits index12;
    int typ, status;

    assert(data);
    typ     = *(int *) ovrr_info;
    status  = 0;

    switch (sid) {

        case VLAN_TABLEm:
            if(bm_obj->vlan_table->max_entries > (uint) dyn_info->index) {
                index12 = dyn_info->index;
                vlan_table_loc_entry = bm_obj->vlan_table->read_entry(&index12);
                vlan_table_loc_entry->unpack_data(data);
                bm_obj->vlan_table->write_entry(&index12, vlan_table_loc_entry);
#ifndef NO_CONSOLE_OUTPUT
                if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
                    vlan_table_loc_entry->print();
                }
#endif
            } else {
                if (bm_obj->vlan_table->max_entries != (uint) dyn_info->index) {
#ifndef NO_CONSOLE_OUTPUT
                    bmi_log->error("ERROR: %s(): Table vlan_table, invalid index (%d)", __FUNCTION__, (uint) dyn_info->index);
#endif
                    return 1;
                }
                if ((typ != 0) && (typ != 2)) {
#ifndef NO_CONSOLE_OUTPUT
                    bmi_log->error("ERROR: %s(): Table vlan_table, invalid operation (%d)", __FUNCTION__, typ);
#endif
                    return 1;
                }
                vlan_table_loc_entry = new vlan_table_entry_t;
                vlan_table_loc_entry->unpack_data(data);
                if (typ == 0) {
                    status = bm_obj->vlan_table->insert_entry(vlan_table_loc_entry);
                } else if (typ == 2) {
                    status = bm_obj->vlan_table->delete_entry(vlan_table_loc_entry);
                }
#ifndef NO_CONSOLE_OUTPUT
                if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
                    vlan_table_loc_entry->print();
                }
#endif
                delete(vlan_table_loc_entry);
            }
            break;

        case SFC_MMU_PROFILEm:
            if(bm_obj->sfc_mmu_profile->max_entries > (uint) dyn_info->index) {
                index1 = dyn_info->index;
                sfc_mmu_profile_loc_entry = bm_obj->sfc_mmu_profile->read_entry(&index1);
                sfc_mmu_profile_loc_entry->unpack_data(data);
                bm_obj->sfc_mmu_profile->write_entry(&index1, sfc_mmu_profile_loc_entry);
#ifndef NO_CONSOLE_OUTPUT
                if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
                    sfc_mmu_profile_loc_entry->print();
                }
#endif
            } else {
                if (bm_obj->sfc_mmu_profile->max_entries != (uint) dyn_info->index) {
#ifndef NO_CONSOLE_OUTPUT
                    bmi_log->error("ERROR: %s(): Table sfc_mmu_profile, invalid index (%d)", __FUNCTION__, (uint) dyn_info->index);
#endif
                    return 1;
                }
                if ((typ != 0) && (typ != 2)) {
#ifndef NO_CONSOLE_OUTPUT
                    bmi_log->error("ERROR: %s(): Table sfc_mmu_profile, invalid operation (%d)", __FUNCTION__, typ);
#endif
                    return 1;
                }
                sfc_mmu_profile_loc_entry = new sfc_mmu_profile_entry_t;
                sfc_mmu_profile_loc_entry->unpack_data(data);
                if (typ == 0) {
                    status = bm_obj->sfc_mmu_profile->insert_entry(sfc_mmu_profile_loc_entry);
                } else if (typ == 2) {
                    status = bm_obj->sfc_mmu_profile->delete_entry(sfc_mmu_profile_loc_entry);
                }
#ifndef NO_CONSOLE_OUTPUT
                if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
                    sfc_mmu_profile_loc_entry->print();
                }
#endif
                delete(sfc_mmu_profile_loc_entry);
            }
            break;

        case SFC_EDB_PROFILEm:
            if(bm_obj->sfc_edb_profile->max_entries > (uint) dyn_info->index) {
                index1 = dyn_info->index;
                sfc_edb_profile_loc_entry = bm_obj->sfc_edb_profile->read_entry(&index1);
                sfc_edb_profile_loc_entry->unpack_data(data);
                bm_obj->sfc_edb_profile->write_entry(&index1, sfc_edb_profile_loc_entry);
#ifndef NO_CONSOLE_OUTPUT
                if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
                    sfc_edb_profile_loc_entry->print();
                }
#endif
            } else {
                if (bm_obj->sfc_edb_profile->max_entries != (uint) dyn_info->index) {
#ifndef NO_CONSOLE_OUTPUT
                    bmi_log->error("ERROR: %s(): Table sfc_edb_profile, invalid index (%d)", __FUNCTION__, (uint) dyn_info->index);
#endif
                    return 1;
                }
                if ((typ != 0) && (typ != 2)) {
#ifndef NO_CONSOLE_OUTPUT
                    bmi_log->error("ERROR: %s(): Table sfc_edb_profile, invalid operation (%d)", __FUNCTION__, typ);
#endif
                    return 1;
                }
                sfc_edb_profile_loc_entry = new sfc_edb_profile_entry_t;
                sfc_edb_profile_loc_entry->unpack_data(data);
                if (typ == 0) {
                    status = bm_obj->sfc_edb_profile->insert_entry(sfc_edb_profile_loc_entry);
                } else if (typ == 2) {
                    status = bm_obj->sfc_edb_profile->delete_entry(sfc_edb_profile_loc_entry);
                }
#ifndef NO_CONSOLE_OUTPUT
                if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
                    sfc_edb_profile_loc_entry->print();
                }
#endif
                delete(sfc_edb_profile_loc_entry);
            }
            break;

        case SFC_IARB_PROFILEm:
            if(bm_obj->sfc_iarb_profile->max_entries > (uint) dyn_info->index) {
                index1 = dyn_info->index;
                sfc_iarb_profile_loc_entry = bm_obj->sfc_iarb_profile->read_entry(&index1);
                sfc_iarb_profile_loc_entry->unpack_data(data);
                bm_obj->sfc_iarb_profile->write_entry(&index1, sfc_iarb_profile_loc_entry);
#ifndef NO_CONSOLE_OUTPUT
                if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
                    sfc_iarb_profile_loc_entry->print();
                }
#endif
            } else {
                if (bm_obj->sfc_iarb_profile->max_entries != (uint) dyn_info->index) {
#ifndef NO_CONSOLE_OUTPUT
                    bmi_log->error("ERROR: %s(): Table sfc_iarb_profile, invalid index (%d)", __FUNCTION__, (uint) dyn_info->index);
#endif
                    return 1;
                }
                if ((typ != 0) && (typ != 2)) {
#ifndef NO_CONSOLE_OUTPUT
                    bmi_log->error("ERROR: %s(): Table sfc_iarb_profile, invalid operation (%d)", __FUNCTION__, typ);
#endif
                    return 1;
                }
                sfc_iarb_profile_loc_entry = new sfc_iarb_profile_entry_t;
                sfc_iarb_profile_loc_entry->unpack_data(data);
                if (typ == 0) {
                    status = bm_obj->sfc_iarb_profile->insert_entry(sfc_iarb_profile_loc_entry);
                } else if (typ == 2) {
                    status = bm_obj->sfc_iarb_profile->delete_entry(sfc_iarb_profile_loc_entry);
                }
#ifndef NO_CONSOLE_OUTPUT
                if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
                    sfc_iarb_profile_loc_entry->print();
                }
#endif
                delete(sfc_iarb_profile_loc_entry);
            }
            break;

        default:
#ifndef NO_CONSOLE_OUTPUT
            bmi_log->error("ERROR: %s() Unknown table sid: 0x%x", __FUNCTION__, sid);
#endif
            break;
    }

    return status;
}

void bm_lt_debug_enable(int en)
{
    debug_en = en;
}

int bm_lt_entry(int unit, bm_sid_t sid, bm_pt_dyn_info_t *dyn_info)
{
    _1bit index1;
    _12bits index12;

    switch (sid) {

        case VLAN_TABLEm:
            index12 = dyn_info->index;
            vlan_table_loc_entry = bm_obj->vlan_table->read_entry(&index12);
#ifndef NO_CONSOLE_OUTPUT
            bmi_log->normal("%s(): vlan_table[%d]:", __FUNCTION__, dyn_info->index);
            vlan_table_loc_entry->print();
#endif
            break;

        case SFC_MMU_PROFILEm:
            index1 = dyn_info->index;
            sfc_mmu_profile_loc_entry = bm_obj->sfc_mmu_profile->read_entry(&index1);
#ifndef NO_CONSOLE_OUTPUT
            bmi_log->normal("%s(): sfc_mmu_profile[%d]:", __FUNCTION__, dyn_info->index);
            sfc_mmu_profile_loc_entry->print();
#endif
            break;

        case SFC_EDB_PROFILEm:
            index1 = dyn_info->index;
            sfc_edb_profile_loc_entry = bm_obj->sfc_edb_profile->read_entry(&index1);
#ifndef NO_CONSOLE_OUTPUT
            bmi_log->normal("%s(): sfc_edb_profile[%d]:", __FUNCTION__, dyn_info->index);
            sfc_edb_profile_loc_entry->print();
#endif
            break;

        case SFC_IARB_PROFILEm:
            index1 = dyn_info->index;
            sfc_iarb_profile_loc_entry = bm_obj->sfc_iarb_profile->read_entry(&index1);
#ifndef NO_CONSOLE_OUTPUT
            bmi_log->normal("%s(): sfc_iarb_profile[%d]:", __FUNCTION__, dyn_info->index);
            sfc_iarb_profile_loc_entry->print();
#endif
            break;

        default:
#ifndef NO_CONSOLE_OUTPUT
            bmi_log->error("ERROR: %s() Unknown table sid: 0x%x", __FUNCTION__, sid);
#endif
            break;
    }

    return 0;
}

