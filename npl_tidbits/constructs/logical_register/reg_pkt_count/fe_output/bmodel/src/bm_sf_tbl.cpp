/*
 * $Copyright: (c) 2018 Broadcom Corp.
 * All Rights Reserved.$
 * File:     bm_sf_tbl.cpp
 * Purpose:  NPL Behavior Modeling SF Table Source
 *
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated from:
 * npl/reg_pkt_count.npl
 * Edits to this file will be lost when it is regenerated.
 *
 */


/*
 * includes
 */
#include "bmodel.h"


/*
 * sf table initialization
 */
void _BModel::_AUTO_sf_tbl_init(void)
{

    _1bit sfc_idx_bits_1;

    sfc_idx_bits_1 = 0;
    sfc_iarb_profile_entry = sfc_iarb_profile->lookup(0, &sfc_idx_bits_1);
    sfc_iarb_profile_entry->set__VALID(1, -1, -1);
    sfc_iarb_profile_entry->set_out_otpid_enable((void*)&control_id->otpid_enable, -1, -1);
    sfc_iarb_profile_entry->set_out_ts_enable((void*)&control_id->ts_enable, -1, -1);
    sfc_iarb_profile_entry->set_out_port_num((void*)&obj_bus->port_num, -1, -1);
    sfc_iarb_profile_entry->set_out_port_type_cfg((void*)&obj_bus->port_type_cfg, -1, -1);
    sfc_iarb_profile_entry->set_out_currenttime((void*)&time_bus->currenttime, -1, -1);
    sfc_iarb_profile->write_entry(&sfc_idx_bits_1, sfc_iarb_profile_entry);

    sfc_idx_bits_1 = 0;
    sfc_mmu_profile_entry = sfc_mmu_profile->lookup(0, &sfc_idx_bits_1);
    sfc_mmu_profile_entry->set__VALID(1, -1, -1);
    sfc_mmu_profile_entry->set_in_l2_pbm((void*)&ccbi->l2_pbm, -1, -1);
    sfc_mmu_profile_entry->set_in_l3_pbm((void*)&ccbi->l3_pbm, -1, -1);
    sfc_mmu_profile_entry->set_out_dst_port((void*)&ccbe->dst_port, -1, -1);
    sfc_mmu_profile->write_entry(&sfc_idx_bits_1, sfc_mmu_profile_entry);

    sfc_idx_bits_1 = 0;
    sfc_edb_profile_entry = sfc_edb_profile->lookup(0, &sfc_idx_bits_1);
    sfc_edb_profile_entry->set__VALID(1, -1, -1);
    sfc_edb_profile_entry->set_in_drop_vector((void*)&egr_aux_bus->drop_vector, -1, -1);
    sfc_edb_profile_entry->set_in_dst_mod((void*)&egr_obj_bus->dst_modid, -1, -1);
    sfc_edb_profile_entry->set_in_dst_port((void*)&egr_obj_bus->dst_port, -1, -1);
    sfc_edb_profile->write_entry(&sfc_idx_bits_1, sfc_edb_profile_entry);

}

