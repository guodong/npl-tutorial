/*
 * $Copyright: (c) 2018 Broadcom Corp.
 * All Rights Reserved.$
 * File:     bmodel.cpp
 * Purpose:  NPL Behavior Modeling Source Code
 *
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated from:
 * npl/reg_tpid.npl
 * Edits to this file will be lost when it is regenerated.
 *
 */


/*
 * includes
 */

#include "bmodel.h"


/*
 * bmodel constructor
 */

_BModel::_BModel() { 


    /*
     * bus instantiations
     */

    obj_bus = new obj_bus_t;
    ccbi = new ccbi_t;
    ccbe = new ccbe_t;
    control_id = new control_id_t;
    time_bus = new time_bus_t;
    egr_obj_bus = new egr_obj_bus_t;
    egr_aux_bus = new aux_bus_t;
    local_bus = new local_bus_t;


    /*
     * packet instantiations
     */

    ingress_pkt = new ingress_pkt_t;


    /*
     * register instantiations
     */

    register_tpid_enable = new tpid_enable;
    register_tpid_values = new tpid_values;


    /*
     * table instantiations
     */

    /* table class instances */
    sfc_mmu_profile = new sfc_mmu_profile_tab_t;
    sfc_edb_profile = new sfc_edb_profile_tab_t;
    sfc_iarb_profile = new sfc_iarb_profile_tab_t;

    /* sfc bookkeeping table */
    sfc_mmu_profile__bk = new sfc_bk_t(2, 3);
    sfc_edb_profile__bk = new sfc_bk_t(2, 3);
    sfc_iarb_profile__bk = new sfc_bk_t(2, 5);

    /* initialize SF tables */
    _AUTO_sf_tbl_init();

}


/*
 * bmodel disstructor
 */

_BModel::~_BModel() { 
    /* buses */
    delete obj_bus;
    delete ccbi;
    delete ccbe;
    delete control_id;
    delete time_bus;
    delete egr_obj_bus;
    delete egr_aux_bus;
    delete local_bus;
    /* packets */
    delete ingress_pkt;
    /* registers */
    delete register_tpid_enable;
    delete register_tpid_values;
    /* table classes */
    delete sfc_mmu_profile;
    delete sfc_edb_profile;
    delete sfc_iarb_profile;
    /* sfc bookkeeping tables */
    delete sfc_mmu_profile__bk;
    delete sfc_edb_profile__bk;
    delete sfc_iarb_profile__bk;

}


/*
 * ing init function
 */

void _BModel::_AUTO_ing_init(void) {

#ifndef NO_CONSOLE_OUTPUT
    if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
        bmi_log->normal("BM_DEBUG: %s() enter", __FUNCTION__);
    }
#endif
    /* reset random generator */
    srand(time(NULL));

    /* reset hdr_ptr */
    hdr_ptr = 0;
    pn_func = 0;

    /* clear ing_pkt_drp_info */
    ing_pkt_drp_info.first_opcode = 0;
    ing_pkt_drp_info.max_opcode = 0;
    ing_pkt_drp_info.max_strn = 0;
    ing_pkt_drp_info.pp_drop = 0;
    ing_pkt_drp_info.hard_pp_drop = 0;
    /* clear ing_pkt_trc_info */
    ing_pkt_trc_info.bitmap = 0;
    /* clear ing_pkt_cnt_info */
    ing_pkt_cnt_info.bitmap = 0;
    in_ing_main = 1;

    /* initialize ing packets */
    ingress_pkt->set_resetval();
    match_id = &ingress_pkt->_match_id;

    /* initialize ing buses */
    if (bus_reset_0) {
        /* reset bus to 0 */
        control_id->set_resetval();
        obj_bus->set_resetval();
        time_bus->set_resetval();
        local_bus->set_resetval();
        ccbe->set_resetval();
        ccbi->set_resetval();
    } else {
        /* reset bus to random values */
        control_id->set_randval();
        obj_bus->set_randval();
        time_bus->set_randval();
        local_bus->set_randval();
        ccbe->set_randval();
        ccbi->set_randval();
    }

    /* initialize ing table pointers */
    /* initialize ing strength table pointers */
    /* initialize ing special function table pointers */
    sfc_iarb_profile_entry = NULL;
    sfc_mmu_profile_entry = NULL;

#ifndef NO_CONSOLE_OUTPUT
    if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
        bmi_log->normal("BM_DEBUG: %s() exit", __FUNCTION__);
    }
#endif
}



/*
 * egr init function
 */

void _BModel::_AUTO_egr_init(void) {

#ifndef NO_CONSOLE_OUTPUT
    if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
        bmi_log->normal("BM_DEBUG: %s() enter", __FUNCTION__);
    }
#endif
    /* clear egr_pkt_drp_info */
    egr_pkt_drp_info.first_opcode = 0;
    egr_pkt_drp_info.max_opcode = 0;
    egr_pkt_drp_info.max_strn = 0;
    egr_pkt_drp_info.pp_drop = 0;
    egr_pkt_drp_info.hard_pp_drop = 0;
    /* clear egr_pkt_trc_info */
    egr_pkt_trc_info.bitmap = 0;
    /* clear egr_pkt_cnt_info */
    egr_pkt_cnt_info.bitmap = 0;
    in_ing_main = 0;

    /* initialize egr packets */

    /* initialize egr only buses */
    if (bus_reset_0) {
        /* reset bus to 0 */
        egr_aux_bus->set_resetval();
        egr_obj_bus->set_resetval();
    } else {
        /* reset bus to random values */
        egr_aux_bus->set_randval();
        egr_obj_bus->set_randval();
    }

    /* initialize egr table pointers */
    /* initialize egr strength table pointers */
    /* initialize egr special function table pointers */
    sfc_mmu_profile_entry = NULL;
    sfc_edb_profile_entry = NULL;

#ifndef NO_CONSOLE_OUTPUT
    if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
        bmi_log->normal("BM_DEBUG: %s() exit", __FUNCTION__);
    }
#endif
}



/*
 * table key functions
 */


/*
 * table action functions
 */


/*
 * parse node functions
 */

void _BModel::_AUTO_PARSER_NODE_start(void) {

#ifndef NO_CONSOLE_OUTPUT
    if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
        bmi_log->normal("BM_DEBUG: %s() enter", __FUNCTION__);
    }
#endif
    /* root_node */
    _AUTO_PARSER_NODE_ethernet();
    return;

#ifndef NO_CONSOLE_OUTPUT
    if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
        bmi_log->normal("BM_DEBUG: %s() exit", __FUNCTION__);
    }
#endif
}


void _BModel::_AUTO_PARSER_NODE_ethernet(void) {
    _1bit set_bit_1;

#ifndef NO_CONSOLE_OUTPUT
    if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
        bmi_log->normal("BM_DEBUG: %s() enter", __FUNCTION__);
    }
#endif
    if (ingress_pkt->group->ether->extract_fields(ing_pkt, &hdr_ptr, &pkt_len)!=0) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->error("ERROR: %s(): extract_fields() error", __FUNCTION__);
#endif
        return;
    }
    ingress_pkt->group->ether->_PRESENT = 1;
    ingress_pkt->group->ether->_PRESENT_CUR = 1;
    update_mid__ingress_pkt__group__ether();
    set_bit_1 = 0x0; 
    local_bus->set_tagged(set_bit_1, 0, 0);
#ifndef NO_CONSOLE_OUTPUT
    if (bm_debug_lvl >= BM_DEBUG_LVL_TRACE) {
        bmi_log->normal("BM_TRACE: ingress_pkt->group->ether->ether_type: 0x%s;  line: %d", ingress_pkt->group->ether->ether_type.to_string(SC_HEX_US, false).c_str(), __LINE__);
        bmi_log->normal("BM_TRACE: register_tpid_enable->reg_val: 0x%s;  line: %d", register_tpid_enable->reg_val.to_string(SC_HEX_US, false).c_str(), __LINE__);
        bmi_log->normal("BM_TRACE: register_tpid_values->tpid0: 0x%s;  line: %d", register_tpid_values->tpid0.to_string(SC_HEX_US, false).c_str(), __LINE__);
    }
#endif
    if (((register_tpid_enable->reg_val & 0x1) && (ingress_pkt->group->ether->ether_type == register_tpid_values->tpid0))) {
#ifndef NO_CONSOLE_OUTPUT
        if (bm_debug_lvl >= BM_DEBUG_LVL_TRACE) {
            bmi_log->normal("BM_TRACE: %s()  line: %d", __FUNCTION__, __LINE__);
        }
#endif
        set_bit_1 = 0x1; 
        local_bus->set_tagged(set_bit_1, 0, 0);
        _AUTO_PARSER_NODE_vlan_tag();
        return;
    }
#ifndef NO_CONSOLE_OUTPUT
    if (bm_debug_lvl >= BM_DEBUG_LVL_TRACE) {
        bmi_log->normal("BM_TRACE: ingress_pkt->group->ether->ether_type: 0x%s;  line: %d", ingress_pkt->group->ether->ether_type.to_string(SC_HEX_US, false).c_str(), __LINE__);
        bmi_log->normal("BM_TRACE: register_tpid_enable->reg_val: 0x%s;  line: %d", register_tpid_enable->reg_val.to_string(SC_HEX_US, false).c_str(), __LINE__);
        bmi_log->normal("BM_TRACE: register_tpid_values->tpid1: 0x%s;  line: %d", register_tpid_values->tpid1.to_string(SC_HEX_US, false).c_str(), __LINE__);
    }
#endif
    if (((register_tpid_enable->reg_val & 0x2) && (ingress_pkt->group->ether->ether_type == register_tpid_values->tpid1))) {
#ifndef NO_CONSOLE_OUTPUT
        if (bm_debug_lvl >= BM_DEBUG_LVL_TRACE) {
            bmi_log->normal("BM_TRACE: %s()  line: %d", __FUNCTION__, __LINE__);
        }
#endif
        set_bit_1 = 0x1; 
        local_bus->set_tagged(set_bit_1, 0, 0);
        _AUTO_PARSER_NODE_vlan_tag();
        return;
    }
#ifndef NO_CONSOLE_OUTPUT
    if (bm_debug_lvl >= BM_DEBUG_LVL_TRACE) {
        bmi_log->normal("BM_TRACE: ingress_pkt->group->ether->ether_type: 0x%s;  line: %d", ingress_pkt->group->ether->ether_type.to_string(SC_HEX_US, false).c_str(), __LINE__);
        bmi_log->normal("BM_TRACE: register_tpid_enable->reg_val: 0x%s;  line: %d", register_tpid_enable->reg_val.to_string(SC_HEX_US, false).c_str(), __LINE__);
        bmi_log->normal("BM_TRACE: register_tpid_values->tpid2: 0x%s;  line: %d", register_tpid_values->tpid2.to_string(SC_HEX_US, false).c_str(), __LINE__);
    }
#endif
    if (((register_tpid_enable->reg_val & 0x4) && (ingress_pkt->group->ether->ether_type == register_tpid_values->tpid2))) {
#ifndef NO_CONSOLE_OUTPUT
        if (bm_debug_lvl >= BM_DEBUG_LVL_TRACE) {
            bmi_log->normal("BM_TRACE: %s()  line: %d", __FUNCTION__, __LINE__);
        }
#endif
        set_bit_1 = 0x1; 
        local_bus->set_tagged(set_bit_1, 0, 0);
        _AUTO_PARSER_NODE_vlan_tag();
        return;
    }
#ifndef NO_CONSOLE_OUTPUT
    if (bm_debug_lvl >= BM_DEBUG_LVL_TRACE) {
        bmi_log->normal("BM_TRACE: ingress_pkt->group->ether->ether_type: 0x%s;  line: %d", ingress_pkt->group->ether->ether_type.to_string(SC_HEX_US, false).c_str(), __LINE__);
        bmi_log->normal("BM_TRACE: register_tpid_enable->reg_val: 0x%s;  line: %d", register_tpid_enable->reg_val.to_string(SC_HEX_US, false).c_str(), __LINE__);
        bmi_log->normal("BM_TRACE: register_tpid_values->tpid3: 0x%s;  line: %d", register_tpid_values->tpid3.to_string(SC_HEX_US, false).c_str(), __LINE__);
    }
#endif
    if (((register_tpid_enable->reg_val & 0x8) && (ingress_pkt->group->ether->ether_type == register_tpid_values->tpid3))) {
#ifndef NO_CONSOLE_OUTPUT
        if (bm_debug_lvl >= BM_DEBUG_LVL_TRACE) {
            bmi_log->normal("BM_TRACE: %s()  line: %d", __FUNCTION__, __LINE__);
        }
#endif
        set_bit_1 = 0x1; 
        local_bus->set_tagged(set_bit_1, 0, 0);
        _AUTO_PARSER_NODE_vlan_tag();
        return;
    }
    _AUTO_PARSER_NODE_ingress();
    return;

#ifndef NO_CONSOLE_OUTPUT
    if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
        bmi_log->normal("BM_DEBUG: %s() exit", __FUNCTION__);
    }
#endif
}


void _BModel::_AUTO_PARSER_NODE_vlan_tag(void) {
    _12bits set_bits_12;

#ifndef NO_CONSOLE_OUTPUT
    if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
        bmi_log->normal("BM_DEBUG: %s() enter", __FUNCTION__);
    }
#endif
    if (ingress_pkt->group->vlan->extract_fields(ing_pkt, &hdr_ptr, &pkt_len)!=0) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->error("ERROR: %s(): extract_fields() error", __FUNCTION__);
#endif
        return;
    }
    ingress_pkt->group->vlan->_PRESENT = 1;
    ingress_pkt->group->vlan->_PRESENT_CUR = 1;
    update_mid__ingress_pkt__group__vlan();
    if (ingress_pkt->group->vlan->_PRESENT_CUR != 1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->error("ERROR: %s() Header ingress_pkt->group->vlan not present", __FUNCTION__);
#endif
    }
    set_bits_12 = ingress_pkt->group->vlan->vid; 
    local_bus->set_vid(set_bits_12, 11, 0);
    _AUTO_PARSER_NODE_ingress();
    return;

#ifndef NO_CONSOLE_OUTPUT
    if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
        bmi_log->normal("BM_DEBUG: %s() exit", __FUNCTION__);
    }
#endif
}


void _BModel::_AUTO_PARSER_NODE_ingress(void) {

#ifndef NO_CONSOLE_OUTPUT
    if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
        bmi_log->normal("BM_DEBUG: %s() enter", __FUNCTION__);
    }
#endif
    /* end_node - parsing done */
    pn_func = 0;

#ifndef NO_CONSOLE_OUTPUT
    if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
        bmi_log->normal("BM_DEBUG: %s() exit", __FUNCTION__);
    }
#endif
}



/*
 * varbit functions
 */


/*
 * functions
 */

void _BModel::base_assign_destination(void) {
    _128bits set_bits_128;
    _7bits set_bits_7;

#ifndef NO_CONSOLE_OUTPUT
    if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
        bmi_log->normal("BM_DEBUG: %s() enter", __FUNCTION__);
    }
#endif
    set_bits_128 = 0; 
    ccbi->set_l3_pbm(set_bits_128, 127, 0);
    set_bits_7 = 0; 
    ccbe->set_dst_port(set_bits_7, 6, 0);
    set_bits_128 = 0x2; 
    ccbi->set_l2_pbm(set_bits_128, 127, 0);

#ifndef NO_CONSOLE_OUTPUT
    if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
        bmi_log->normal("BM_DEBUG: %s() exit", __FUNCTION__);
    }
#endif
}


void _BModel::base_egress(void) {
    _16bits set_bits_16;
    _8bits set_bits_8;
    _7bits set_bits_7;

#ifndef NO_CONSOLE_OUTPUT
    if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
        bmi_log->normal("BM_DEBUG: %s() enter", __FUNCTION__);
    }
#endif
    set_bits_16 = 0; 
    egr_aux_bus->set_drop_vector(set_bits_16, 15, 0);
    set_bits_8 = 0; 
    egr_obj_bus->set_dst_modid(set_bits_8, 7, 0);
    set_bits_7 = ccbe->dst_port; 
    egr_obj_bus->set_dst_port(set_bits_7, 6, 0);

#ifndef NO_CONSOLE_OUTPUT
    if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
        bmi_log->normal("BM_DEBUG: %s() exit", __FUNCTION__);
    }
#endif
}



/*
 * ingress main
 */

void _BModel::ing_main(void) {
    _1bit sfc_idx_bits_1;

#ifndef NO_CONSOLE_OUTPUT
    if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
        bmi_log->normal("BM_DEBUG: %s() enter", __FUNCTION__);
    }
#endif

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->normal("bm_debug_lvl = %d", bm_debug_lvl);

    bmi_log->normal("###### Starting Ingress Pipeline Processing ######");
#endif

    /* initialize packets and buses */
    _AUTO_ing_init();

    sfc_idx_bits_1 = 0;
    sfc_iarb_profile_entry = sfc_iarb_profile->lookup(0, &sfc_idx_bits_1);
    sfc_iarb_profile__sfc_call((void*)sfc_iarb_profile_entry, sfc_idx_bits_1);
    _AUTO_PARSER_NODE_start();
#ifndef NO_CONSOLE_OUTPUT
    if (bm_debug_lvl >= BM_DEBUG_LVL_TRACE) {
        bmi_log->normal("BM_TRACE: ingress_pkt->group->vlan->_PRESENT: 0x%s;  line: %d", ingress_pkt->group->vlan->_PRESENT.to_string(SC_HEX_US, false).c_str(), __LINE__);
    }
#endif
    if ((ingress_pkt->group->vlan->_PRESENT != 0)) {
#ifndef NO_CONSOLE_OUTPUT
        if (bm_debug_lvl >= BM_DEBUG_LVL_TRACE) {
            bmi_log->normal("BM_TRACE: %s()  line: %d", __FUNCTION__, __LINE__);
        }
#endif
        printf("It is a tagged packet, VLAN ID = %d\n", (int)local_bus->vid);
    } else {
#ifndef NO_CONSOLE_OUTPUT
        if (bm_debug_lvl >= BM_DEBUG_LVL_TRACE) {
            bmi_log->normal("BM_TRACE: %s()  line: %d", __FUNCTION__, __LINE__);
        }
#endif
        printf("It is a untagged packet.\n");
    }
    base_assign_destination();
    sfc_idx_bits_1 = 0;
    sfc_mmu_profile_entry = sfc_mmu_profile->lookup(0, &sfc_idx_bits_1);
    sfc_mmu_profile__sfc_call((void*)sfc_mmu_profile_entry, sfc_idx_bits_1);

#ifndef NO_CONSOLE_OUTPUT
    if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
        bmi_log->normal("BM_DEBUG: %s() exit", __FUNCTION__);
    }
#endif
}



/*
 * egress main
 */

void _BModel::egr_main(void) {
    _1bit sfc_idx_bits_1;

#ifndef NO_CONSOLE_OUTPUT
    if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
        bmi_log->normal("BM_DEBUG: %s() enter", __FUNCTION__);
    }
#endif

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->normal("##### Starting Egress Pipeline Processing #####");
#endif

    /* initialize egr buses */
    _AUTO_egr_init();

    sfc_idx_bits_1 = 0;
    sfc_mmu_profile_entry = sfc_mmu_profile->lookup(0, &sfc_idx_bits_1);
    sfc_mmu_profile__sfc_call((void*)sfc_mmu_profile_entry, sfc_idx_bits_1);
    base_egress();
    sfc_idx_bits_1 = 0;
    sfc_edb_profile_entry = sfc_edb_profile->lookup(0, &sfc_idx_bits_1);
    sfc_edb_profile__sfc_call((void*)sfc_edb_profile_entry, sfc_idx_bits_1);

#ifndef NO_CONSOLE_OUTPUT
    if (bm_debug_lvl >= BM_DEBUG_LVL_DEBUG_NZ) {
        bmi_log->normal("BM_DEBUG: %s() exit", __FUNCTION__);
    }
#endif
}
