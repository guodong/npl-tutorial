/*
 * $Copyright: (c) 2018 Broadcom Corp.
 * All Rights Reserved.$
 * File:     bmodel.h
 * Purpose:  NPL Behavior Modeling header file
 *
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated from:
 * npl/packet_count.npl
 * Edits to this file will be lost when it is regenerated.
 *
 */

#ifndef _BMODEL_H_
#define _BMODEL_H_


/*
 * includes
 */

#include <stdlib.h>
#include <time.h>
#include "include_libs.h"
#include "table_entry_classes.h"
#include "table_classes.h"
#include "header_classes.h"
#include "reg_classes.h"
#include "format_classes.h"


/*
 * defines
 */

#define MAX_ENCAP 112
#define NUM_BYTES_CRC 4
#define HEADER_PAYLOAD_CHKSUM 1
#define BIT_BASE_BOUNDRY 64
#define HARD_DROP_MIN 128
#define TRACE_CODE_MAX 47
#define COUNT_ID_MAX 63


/*
 * enums
 */

enum pn_func_enum {
    PARSER_NODE_start_enum = 1,
    PARSER_NODE_ethernet_enum,
    PARSER_NODE_ingress_enum
};


/*
 * packet drop info struct
 */

typedef struct pkt_drop_info_s {
    _8bits  first_opcode;
    _8bits  max_opcode;
    _4bits  max_strn;
    _1bit   pp_drop;
    _1bit   hard_pp_drop;
} pkt_drop_info_t;


/*
 * packet trace info struct
 */

typedef struct pkt_trace_info_s {
    _48bits  bitmap;
} pkt_trace_info_t;


/*
 * packet count info struct
 */

typedef struct pkt_count_info_s {
    _64bits  bitmap;
} pkt_count_info_t;


/*
 * sf bookkeeping struct
 */

typedef struct arg_addr_info_s {
    int     hit;
    void    *addr;
    int     size;
    int     high;
    int     low;
} arg_addr_info_t;


/*
 * sf bookkeeping class
 */

class sfc_bk_t {
private:
    arg_addr_info_t *table;

public:
    int table_rows;
    int table_cols;

    sfc_bk_t(int size, int num_args);
    ~sfc_bk_t();
    void arg_set(int, int, void*, int, int, int);
    int idx_hit(int);
    int idx_arg_hit(int, int);
    arg_addr_info_t *idx_arg_get(int, int);
};



/*
 * bmodel class
 */

class _BModel {

    public:

    _BModel();
    ~_BModel();


    /* variables */
    _8bits *ing_pkt = NULL;
    _8bits *egr_pkt = NULL;
    _32bits hdr_ptr;
    _32bits pkt_len;
    pkt_drop_info_t ing_pkt_drp_info;
    pkt_drop_info_t egr_pkt_drp_info;
    pkt_trace_info_t ing_pkt_trc_info;
    pkt_trace_info_t egr_pkt_trc_info;
    pkt_count_info_t ing_pkt_cnt_info;
    pkt_count_info_t egr_pkt_cnt_info;
    int in_ing_main;
    int test_status;
    int pn_func;
    _1bit*match_id;
    _32bits match_id_width = 1;

    /* buses */
    obj_bus_t *obj_bus = NULL;
    ccbi_t *ccbi = NULL;
    ccbe_t *ccbe = NULL;
    control_id_t *control_id = NULL;
    time_bus_t *time_bus = NULL;
    egr_obj_bus_t *egr_obj_bus = NULL;
    aux_bus_t *egr_aux_bus = NULL;
    local_bus_t *local_bus = NULL;

    /* packets */
    ingress_pkt_t *ingress_pkt = NULL;

    /* table classes*/
    sfc_mmu_profile_tab_t *sfc_mmu_profile = NULL;
    sfc_edb_profile_tab_t *sfc_edb_profile = NULL;
    sfc_iarb_profile_tab_t *sfc_iarb_profile = NULL;

    /* table instances */
    sfc_mmu_profile_entry_t *sfc_mmu_profile_entry = NULL;
    sfc_edb_profile_entry_t *sfc_edb_profile_entry = NULL;
    sfc_iarb_profile_entry_t *sfc_iarb_profile_entry = NULL;

    /* bookkeeping table instances */
    sfc_bk_t *sfc_mmu_profile__bk = NULL;
    sfc_bk_t *sfc_edb_profile__bk = NULL;
    sfc_bk_t *sfc_iarb_profile__bk = NULL;

    /* prototypes */
    #include "mid_functions.h"
    void _AUTO_ing_init(void);
    void _AUTO_egr_init(void);
    void _AUTO_sf_tbl_init(void);
    void _AUTO_PARSER_NODE_start(void);
    void _AUTO_PARSER_NODE_ethernet(void);
    void _AUTO_PARSER_NODE_ingress(void);
    void base_assign_destination(void);
    void base_egress(void);
    void do_mc_pkt_count(void);
    void ing_main(void);
    void egr_main(void);

    /* sf wrap prototypes */
    void sfc_mmu_profile__sfc_call(void*, int);
    void sfc_edb_profile__sfc_call(void*, int);
    void sfc_iarb_profile__sfc_call(void*, int);

    /*                                   */
    /* User Supplied Function Prototypes */
    /*                                   */

    /* checksum prototypes */

    /* update packet length prototypes */

    /* editor prototypes */
    virtual void add_header(_8bits*, void*, void*);
    virtual void add_header_pkt(_8bits *pkt, void *ptr0, uint8 pos, void *ptr1);
    virtual void delete_header(_8bits*, void*);
    virtual void packet_length_update(void*, void*, _32bits*, _8bits*, _8bits*);

    /* packet prototypes */
    virtual void packet_drop(_8bits*, _8bits*, _4bits*);
    virtual void packet_trace(_8bits*, _8bits*);
    virtual void packet_count(_8bits*, _8bits*);

    /* sf call prototypes */
    virtual void sfc_mmu_func(_128bits*, _128bits*, _7bits*, int*);
    virtual void sfc_edb_func(_16bits*, _8bits*, _7bits*);
    virtual void sfc_iarb_func(_4bits*, _1bit*, _7bits*, _2bits*, _16bits*);

};

#endif /* _BMODEL_H_ */
