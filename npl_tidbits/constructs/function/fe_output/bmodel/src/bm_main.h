/*
 * $Copyright: (c) 2018 Broadcom Corp.
 * All Rights Reserved.$
 * File:     bm_main.h
 * Purpose:  NPL Behavior Modeling Main Header
 *
 * DO NOT EDIT THIS FILE!
 * Edits to this file will be lost when it is regenerated.
 *
 */
#ifndef _BM_MAIN_H_
#define _BM_MAIN_H_

#ifdef BM_IN_TARGET_PP_TOP

/*
 * includes
 */

#include "target_pp_top.h"


/*
 * externs
 */

extern target_pp_top *bm_obj;


/*
 * function prototypes
 */

void bm_ngsdk_init(target_pp_top *obj);
void bm_ngsdk_free(void);

#else

/*
 * includes
 */

#include "bmodel.h"


/*
 * externs
 */

extern _BModel *bm_obj;


/*
 * function prototypes
 */

void bm_ngsdk_init(_BModel *obj);
void bm_ngsdk_free(void);

#endif /* BM_IN_TARGET_PP_TOP */

#endif /* _BM_MAIN_H_ */
