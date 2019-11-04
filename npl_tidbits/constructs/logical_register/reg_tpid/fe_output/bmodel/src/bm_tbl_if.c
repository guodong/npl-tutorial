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
    int typ, status;

    assert(data);
    typ = *(int *) ovrr_info;
    status = 0;

    switch (sid) {

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

        case TPID_ENABLEm:
#ifndef NO_CONSOLE_OUTPUT
            if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
                bmi_log->normal("%s(): register_tpid_enable:", __FUNCTION__);
                bm_obj->register_tpid_enable->print();
            }
#endif
            field = (uint32_t)bm_obj->register_tpid_enable->reg_val;
            bm_field_set(data, 0, 3, &field);
            break;

        case TPID_VALUESm:
#ifndef NO_CONSOLE_OUTPUT
            if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
                bmi_log->normal("%s(): register_tpid_values:", __FUNCTION__);
                bm_obj->register_tpid_values->print();
            }
#endif
            field = (uint32_t)bm_obj->register_tpid_values->tpid0;
            bm_field_set(data, 0, 15, &field);
            field = (uint32_t)bm_obj->register_tpid_values->tpid1;
            bm_field_set(data, 16, 31, &field);
            field = (uint32_t)bm_obj->register_tpid_values->tpid2;
            bm_field_set(data, 32, 47, &field);
            field = (uint32_t)bm_obj->register_tpid_values->tpid3;
            bm_field_set(data, 48, 63, &field);
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
    int typ, status;

    assert(data);
    typ     = *(int *) ovrr_info;
    status  = 0;

    switch (sid) {

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

        case TPID_ENABLEm:
            bm_field_get(data, 0, 3, &field);
            bm_obj->register_tpid_enable->set_reg_val((_4bits)field, -1, -1);
#ifndef NO_CONSOLE_OUTPUT
            if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
                bmi_log->normal("%s(): register_tpid_enable:", __FUNCTION__);
                bm_obj->register_tpid_enable->print();
            }
#endif
            break;

        case TPID_VALUESm:
            bm_field_get(data, 0, 15, &field);
            bm_obj->register_tpid_values->set_tpid0((_16bits)field, -1, -1);
            bm_field_get(data, 16, 31, &field);
            bm_obj->register_tpid_values->set_tpid1((_16bits)field, -1, -1);
            bm_field_get(data, 32, 47, &field);
            bm_obj->register_tpid_values->set_tpid2((_16bits)field, -1, -1);
            bm_field_get(data, 48, 63, &field);
            bm_obj->register_tpid_values->set_tpid3((_16bits)field, -1, -1);
#ifndef NO_CONSOLE_OUTPUT
            if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
                bmi_log->normal("%s(): register_tpid_values:", __FUNCTION__);
                bm_obj->register_tpid_values->print();
            }
#endif
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

    switch (sid) {

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
