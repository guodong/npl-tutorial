/*
 * $Copyright: (c) 2018 Broadcom Corp.
 * All Rights Reserved.$
 * File:     bm_mgmt_if.c
 * Purpose:  Behavior Model management table interface source
 *
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated
 * Edits to this file will be lost when it is regenerated.
 *
 */

#include "include_libs.h"
#include "bm_field.h"
#include "bm_tbl_if.h"
#include "bm_sfpt_if.h"
#include "bm_main.h"


int bm_mgmt_read(int unit, bm_sid_t sid,
               bm_pt_dyn_info_t *dyn_info, void *ovrr_info,
               uint32_t *data, size_t wsize)
{
    if (sid>=SFC_EDB_PROFILEm && sid<=SFC_MMU_PROFILEm) {
        return bm_pt_read(unit, sid, dyn_info, ovrr_info, data, wsize);
    }

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->error("ERROR: %s() Unknown table sid: 0x%x", __FUNCTION__, sid);
#endif
    return 1;
}

int bm_mgmt_write(int unit, bm_sid_t sid,
                bm_pt_dyn_info_t *dyn_info, void *ovrr_info,
                uint32_t *data)
{
    if (sid>=SFC_EDB_PROFILEm && sid<=SFC_MMU_PROFILEm) {
        return bm_pt_write(unit, sid, dyn_info, ovrr_info, data);
    }

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->error("ERROR: %s() Unknown table sid: 0x%x", __FUNCTION__, sid);
#endif
    return 1;
}

void bm_mgmt_debug_enable(int en)
{
    bm_lt_debug_enable(en);
}

int bm_mgmt_lt_entry(int unit, bm_sid_t sid, bm_pt_dyn_info_t *dyn_info)
{
    if (sid>=SFC_EDB_PROFILEm && sid<=SFC_MMU_PROFILEm) {
        return bm_lt_entry(unit, sid, dyn_info);
    }

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->error("ERROR: %s() Unknown table sid: 0x%x", __FUNCTION__, sid);
#endif
    return 1;
}
