/*
 * $Copyright: (c) 2018 Broadcom Corp.
 * All Rights Reserved.$
 * File:     bm_sf.cpp
 * Purpose:  NPL Behavior Modeling SF source code
 *
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated from:
 * npl/strength_vid.npl
 * Edits to this file will be lost when it is regenerated.
 *
 */


/*
 * includes
 */

#include "bmodel.h"


/*
 * sfc class methods
 */

sfc_bk_t::sfc_bk_t(int size, int num_args) {
    int idx;
    /* create the table */
    table = new arg_addr_info_t[size*num_args];
    table_rows = size;
    table_cols = num_args;
    /* clear hit */
    for (idx=0; idx<(size*num_args); idx++) {
        table[idx].hit = 0;
    }
}

sfc_bk_t::~sfc_bk_t() {
    /* remove the table */
    delete [] table;
}

void sfc_bk_t::arg_set(int index, int arg, void *addr, int size, int high, int low)
{
    int idx = index*table_cols+arg;
    assert(index < table_rows);
    assert(arg < table_cols);
    table[idx].addr = addr;
    table[idx].size = size;
    table[idx].high = high;
    table[idx].low = low;
    table[idx].hit = 1;
}

int sfc_bk_t::idx_hit(int index)
{
    int arg;
    assert(index < table_rows);
    for (arg=0; arg<table_cols; arg++) {
        if (table[index*table_cols+arg].hit) {
            return 1;
        }
    }
    return 0;
}

int sfc_bk_t::idx_arg_hit(int index, int arg)
{
    if (table[index*table_cols+arg].hit) {
        return 1;
    }
    return 0;
}

arg_addr_info_t *sfc_bk_t::idx_arg_get(int index, int arg)
{
    return &table[index*table_cols+arg];
}


/*
 * sfc calls
 */

void _BModel::sfc_mmu_profile__sfc_call(void *tbl_ptr, int index)
{
    sfc_mmu_profile_entry_t *entry_ptr = (sfc_mmu_profile_entry_t *)tbl_ptr;
    arg_addr_info_t *arg_info;
    _bits_ull_base_t *bub;
    _bits_base_t *bb;
    _128bits arg_0_val = 0;
    _128bits *arg_0 = &arg_0_val;
    _128bits arg_1_val = 0;
    _128bits *arg_1 = &arg_1_val;
    _7bits arg_2_val = 0;
    _7bits *arg_2 = &arg_2_val;

#ifndef NO_CONSOLE_OUTPUT
    if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
        bmi_log->normal("BM_DEBUG: %s() enter", __FUNCTION__);
    }
#endif

    assert(index < sfc_mmu_profile__bk->table_rows);

    /* load arguments */
    if (entry_ptr->in_l2_pbm == NULL) {
        arg_0 = NULL;
    }
    else if (sfc_mmu_profile__bk->idx_arg_hit(index, 0)) {
        arg_info = sfc_mmu_profile__bk->idx_arg_get(index, 0);
        if (arg_info->size <= BIT_BASE_BOUNDRY) {
            bub = (_bits_ull_base_t*)arg_info->addr;
            *arg_0 = bub->range(arg_info->high, arg_info->low);
        } else {
            bb = (_bits_base_t*)arg_info->addr;
            *arg_0 = bb->range(arg_info->high, arg_info->low);
        }
    }
    else {
        arg_0 = (_128bits*)entry_ptr->in_l2_pbm;
    }

    if (entry_ptr->in_l3_pbm == NULL) {
        arg_1 = NULL;
    }
    else if (sfc_mmu_profile__bk->idx_arg_hit(index, 1)) {
        arg_info = sfc_mmu_profile__bk->idx_arg_get(index, 1);
        if (arg_info->size <= BIT_BASE_BOUNDRY) {
            bub = (_bits_ull_base_t*)arg_info->addr;
            *arg_1 = bub->range(arg_info->high, arg_info->low);
        } else {
            bb = (_bits_base_t*)arg_info->addr;
            *arg_1 = bb->range(arg_info->high, arg_info->low);
        }
    }
    else {
        arg_1 = (_128bits*)entry_ptr->in_l3_pbm;
    }

    if (entry_ptr->out_dst_port == NULL) {
        /* output - use local variable */
    }
    else if (sfc_mmu_profile__bk->idx_arg_hit(index, 2)) {
        arg_info = sfc_mmu_profile__bk->idx_arg_get(index, 2);
        if (arg_info->size <= BIT_BASE_BOUNDRY) {
            bub = (_bits_ull_base_t*)arg_info->addr;
            *arg_2 = bub->range(arg_info->high, arg_info->low);
        } else {
            bb = (_bits_base_t*)arg_info->addr;
            *arg_2 = bb->range(arg_info->high, arg_info->low);
        }
    }
    else {
        *arg_2 = *(_7bits*)entry_ptr->out_dst_port;
    }


    /* call special function */
    sfc_mmu_func(arg_0, arg_1, arg_2, &in_ing_main);

    /* write output arguments */
    switch (index) {
        case (0): {
            ccbe->set_dst_port(*arg_2, 6, 0);
            break;
        }
        default: {
#ifndef NO_CONSOLE_OUTPUT
            bmi_log->normal("%s() UNKNOWN index: %d; writing to table entry", __FUNCTION__, index);
#endif
            if (entry_ptr->out_dst_port != NULL) {
                arg_2 = (_7bits*)entry_ptr->out_dst_port;
                *arg_2 = arg_2_val;
            }
            break;
        }
    }

#ifndef NO_CONSOLE_OUTPUT
    if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
        bmi_log->normal("BM_DEBUG: %s() exit", __FUNCTION__);
    }
#endif
}

void _BModel::sfc_edb_profile__sfc_call(void *tbl_ptr, int index)
{
    sfc_edb_profile_entry_t *entry_ptr = (sfc_edb_profile_entry_t *)tbl_ptr;
    arg_addr_info_t *arg_info;
    _bits_ull_base_t *bub;
    _bits_base_t *bb;
    _16bits arg_0_val = 0;
    _16bits *arg_0 = &arg_0_val;
    _8bits arg_1_val = 0;
    _8bits *arg_1 = &arg_1_val;
    _7bits arg_2_val = 0;
    _7bits *arg_2 = &arg_2_val;

#ifndef NO_CONSOLE_OUTPUT
    if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
        bmi_log->normal("BM_DEBUG: %s() enter", __FUNCTION__);
    }
#endif

    assert(index < sfc_edb_profile__bk->table_rows);

    /* load arguments */
    if (entry_ptr->in_drop_vector == NULL) {
        arg_0 = NULL;
    }
    else if (sfc_edb_profile__bk->idx_arg_hit(index, 0)) {
        arg_info = sfc_edb_profile__bk->idx_arg_get(index, 0);
        if (arg_info->size <= BIT_BASE_BOUNDRY) {
            bub = (_bits_ull_base_t*)arg_info->addr;
            *arg_0 = bub->range(arg_info->high, arg_info->low);
        } else {
            bb = (_bits_base_t*)arg_info->addr;
            *arg_0 = bb->range(arg_info->high, arg_info->low);
        }
    }
    else {
        arg_0 = (_16bits*)entry_ptr->in_drop_vector;
    }

    if (entry_ptr->in_dst_mod == NULL) {
        arg_1 = NULL;
    }
    else if (sfc_edb_profile__bk->idx_arg_hit(index, 1)) {
        arg_info = sfc_edb_profile__bk->idx_arg_get(index, 1);
        if (arg_info->size <= BIT_BASE_BOUNDRY) {
            bub = (_bits_ull_base_t*)arg_info->addr;
            *arg_1 = bub->range(arg_info->high, arg_info->low);
        } else {
            bb = (_bits_base_t*)arg_info->addr;
            *arg_1 = bb->range(arg_info->high, arg_info->low);
        }
    }
    else {
        arg_1 = (_8bits*)entry_ptr->in_dst_mod;
    }

    if (entry_ptr->in_dst_port == NULL) {
        arg_2 = NULL;
    }
    else if (sfc_edb_profile__bk->idx_arg_hit(index, 2)) {
        arg_info = sfc_edb_profile__bk->idx_arg_get(index, 2);
        if (arg_info->size <= BIT_BASE_BOUNDRY) {
            bub = (_bits_ull_base_t*)arg_info->addr;
            *arg_2 = bub->range(arg_info->high, arg_info->low);
        } else {
            bb = (_bits_base_t*)arg_info->addr;
            *arg_2 = bb->range(arg_info->high, arg_info->low);
        }
    }
    else {
        arg_2 = (_7bits*)entry_ptr->in_dst_port;
    }


    /* call special function */
    sfc_edb_func(arg_0, arg_1, arg_2);

    /* no output arguments */

#ifndef NO_CONSOLE_OUTPUT
    if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
        bmi_log->normal("BM_DEBUG: %s() exit", __FUNCTION__);
    }
#endif
}

void _BModel::sfc_iarb_profile__sfc_call(void *tbl_ptr, int index)
{
    sfc_iarb_profile_entry_t *entry_ptr = (sfc_iarb_profile_entry_t *)tbl_ptr;
    arg_addr_info_t *arg_info;
    _bits_ull_base_t *bub;
    _bits_base_t *bb;
    _4bits arg_0_val = 0;
    _4bits *arg_0 = &arg_0_val;
    _1bit arg_1_val = 0;
    _1bit *arg_1 = &arg_1_val;
    _7bits arg_2_val = 0;
    _7bits *arg_2 = &arg_2_val;
    _2bits arg_3_val = 0;
    _2bits *arg_3 = &arg_3_val;
    _16bits arg_4_val = 0;
    _16bits *arg_4 = &arg_4_val;

#ifndef NO_CONSOLE_OUTPUT
    if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
        bmi_log->normal("BM_DEBUG: %s() enter", __FUNCTION__);
    }
#endif

    assert(index < sfc_iarb_profile__bk->table_rows);

    /* load arguments */
    if (entry_ptr->out_otpid_enable == NULL) {
        /* output - use local variable */
    }
    else if (sfc_iarb_profile__bk->idx_arg_hit(index, 0)) {
        arg_info = sfc_iarb_profile__bk->idx_arg_get(index, 0);
        if (arg_info->size <= BIT_BASE_BOUNDRY) {
            bub = (_bits_ull_base_t*)arg_info->addr;
            *arg_0 = bub->range(arg_info->high, arg_info->low);
        } else {
            bb = (_bits_base_t*)arg_info->addr;
            *arg_0 = bb->range(arg_info->high, arg_info->low);
        }
    }
    else {
        *arg_0 = *(_4bits*)entry_ptr->out_otpid_enable;
    }

    if (entry_ptr->out_ts_enable == NULL) {
        /* output - use local variable */
    }
    else if (sfc_iarb_profile__bk->idx_arg_hit(index, 1)) {
        arg_info = sfc_iarb_profile__bk->idx_arg_get(index, 1);
        if (arg_info->size <= BIT_BASE_BOUNDRY) {
            bub = (_bits_ull_base_t*)arg_info->addr;
            *arg_1 = bub->range(arg_info->high, arg_info->low);
        } else {
            bb = (_bits_base_t*)arg_info->addr;
            *arg_1 = bb->range(arg_info->high, arg_info->low);
        }
    }
    else {
        *arg_1 = *(_1bit*)entry_ptr->out_ts_enable;
    }

    if (entry_ptr->out_port_num == NULL) {
        /* output - use local variable */
    }
    else if (sfc_iarb_profile__bk->idx_arg_hit(index, 2)) {
        arg_info = sfc_iarb_profile__bk->idx_arg_get(index, 2);
        if (arg_info->size <= BIT_BASE_BOUNDRY) {
            bub = (_bits_ull_base_t*)arg_info->addr;
            *arg_2 = bub->range(arg_info->high, arg_info->low);
        } else {
            bb = (_bits_base_t*)arg_info->addr;
            *arg_2 = bb->range(arg_info->high, arg_info->low);
        }
    }
    else {
        *arg_2 = *(_7bits*)entry_ptr->out_port_num;
    }

    if (entry_ptr->out_port_type_cfg == NULL) {
        /* output - use local variable */
    }
    else if (sfc_iarb_profile__bk->idx_arg_hit(index, 3)) {
        arg_info = sfc_iarb_profile__bk->idx_arg_get(index, 3);
        if (arg_info->size <= BIT_BASE_BOUNDRY) {
            bub = (_bits_ull_base_t*)arg_info->addr;
            *arg_3 = bub->range(arg_info->high, arg_info->low);
        } else {
            bb = (_bits_base_t*)arg_info->addr;
            *arg_3 = bb->range(arg_info->high, arg_info->low);
        }
    }
    else {
        *arg_3 = *(_2bits*)entry_ptr->out_port_type_cfg;
    }

    if (entry_ptr->out_currenttime == NULL) {
        /* output - use local variable */
    }
    else if (sfc_iarb_profile__bk->idx_arg_hit(index, 4)) {
        arg_info = sfc_iarb_profile__bk->idx_arg_get(index, 4);
        if (arg_info->size <= BIT_BASE_BOUNDRY) {
            bub = (_bits_ull_base_t*)arg_info->addr;
            *arg_4 = bub->range(arg_info->high, arg_info->low);
        } else {
            bb = (_bits_base_t*)arg_info->addr;
            *arg_4 = bb->range(arg_info->high, arg_info->low);
        }
    }
    else {
        *arg_4 = *(_16bits*)entry_ptr->out_currenttime;
    }


    /* call special function */
    sfc_iarb_func(arg_0, arg_1, arg_2, arg_3, 
                arg_4);

    /* write output arguments */
    switch (index) {
        case (0): {
            control_id->set_otpid_enable(*arg_0, 3, 0);
            control_id->set_ts_enable(*arg_1, 0, 0);
            obj_bus->set_port_num(*arg_2, 6, 0);
            obj_bus->set_port_type_cfg(*arg_3, 1, 0);
            time_bus->set_currenttime(*arg_4, 15, 0);
            break;
        }
        default: {
#ifndef NO_CONSOLE_OUTPUT
            bmi_log->normal("%s() UNKNOWN index: %d; writing to table entry", __FUNCTION__, index);
#endif
            if (entry_ptr->out_otpid_enable != NULL) {
                arg_0 = (_4bits*)entry_ptr->out_otpid_enable;
                *arg_0 = arg_0_val;
            }
            if (entry_ptr->out_ts_enable != NULL) {
                arg_1 = (_1bit*)entry_ptr->out_ts_enable;
                *arg_1 = arg_1_val;
            }
            if (entry_ptr->out_port_num != NULL) {
                arg_2 = (_7bits*)entry_ptr->out_port_num;
                *arg_2 = arg_2_val;
            }
            if (entry_ptr->out_port_type_cfg != NULL) {
                arg_3 = (_2bits*)entry_ptr->out_port_type_cfg;
                *arg_3 = arg_3_val;
            }
            if (entry_ptr->out_currenttime != NULL) {
                arg_4 = (_16bits*)entry_ptr->out_currenttime;
                *arg_4 = arg_4_val;
            }
            break;
        }
    }

#ifndef NO_CONSOLE_OUTPUT
    if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
        bmi_log->normal("BM_DEBUG: %s() exit", __FUNCTION__);
    }
#endif
}



/*
 * fp dt calls
 */

