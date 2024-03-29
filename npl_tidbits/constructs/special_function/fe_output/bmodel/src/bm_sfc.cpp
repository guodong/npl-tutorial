/*
 * $Copyright: (c) 2018 Broadcom Corp.
 * All Rights Reserved.$
 * File:     bm_sfc.cpp
 * Purpose:  NPL Behavior Modeling SF Calls source code
 *
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated from:
 * npl/sf_timestamping.npl
 * Edits to this file will be lost when it is regenerated.
 *
 */


/*
 * includes
 */

#include "bmodel.h"


/*
 * sf call definitions
 */

void _BModel::sfc_mmu_func(
        _128bits *in_l2_pbm, _128bits *in_l3_pbm, _7bits *out_dst_port, int *in_ingress)
{

    /* SF Logic Here */

}

void _BModel::sfc_edb_func(
        _16bits *in_drop_vector, _8bits *in_dst_mod, _7bits *in_dst_port)
{

    /* SF Logic Here */

}

void _BModel::sfc_iarb_func(
        _4bits *out_otpid_enable, _1bit *out_ts_enable, _7bits *out_port_num, _2bits *out_port_type_cfg, 
        _16bits *out_currenttime)
{

    /* SF Logic Here */

}

void _BModel::sfc_timestamping_func(
        _1bit *in_ts_enable, _1bit *out_ts_valid, _32bits *out_ts_val_sec, _32bits *out_ts_val_nsec)
{

    /* SF Logic Here */

}

