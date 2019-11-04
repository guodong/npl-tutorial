/*
 * $Copyright: (c) 2018 Broadcom Corp.
 * All Rights Reserved.$
 * File:     bm_sfpt_if.h
 * Purpose:  Behavior Model sf physical table interface header
 *
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated
 * Edits to this file will be lost when it is regenerated.
 *
 */

#ifndef _BM_SFPT_IF_H_
#define _BM_SFPT_IF_H_


#include "include_libs.h"
#include "bm_ext_if.h"

/*!
 * \brief Read device table entry.
 *
 * Common entry point for reading a physical table entry.
 *
 * The table entry may be a memory entry or a register.
 *
 * The function implementation relies on device-specific driver
 * functions for interpreting the address components
 *
 * \param [in] unit Unit number.
 * \param [in] sid Device-specific symbol ID for physical table.
 * \param [in] dyn_info Device-specific structure of dynamic address components,
 *             typically the table index to read from.
 * \param [in] ovrr_info Optional device-specific override structure, which can
 *             be used to override otherwise fixed address components, such as
 *             the access type.
 * \param [in] data Buffer where to return the table entry contents.
 * \param [in] wsize Size of buffer in units of 32-bit words.
 *
 * \retval SHR_E_NONE Table entry read successfully.
 */
extern int
bm_sfpt_read(int unit, bm_sid_t sid,
            bm_pt_dyn_info_t *dyn_info, void *ovrr_info,
            uint32_t *data, size_t wsize);

/*!
 * \brief Write device table entry.
 *
 * Common entry point for writing a physical table entry.
 *
 * The table entry may be a memory entry or a register.
 *
 * The function implementation relies on device-specific driver
 * functions for interpreting the address components
 *
 * \param [in] unit Unit number.
 * \param [in] sid Device-specific symbol ID for physical table.
 * \param [in] dyn_info Device-specific structure of dynamic address components,
 *             typically the table index to write.
 * \param [in] ovrr_info Optional device-specific override structure, which can
 *             be used to override otherwise fixed address components, such as
 *             the access type.
 * \param [in] data Data buffer to write to the table entry.
 *
 * \retval SHR_E_NONE Table entry written successfully.
 */
extern int
bm_sfpt_write(int unit, bm_sid_t sid,
             bm_pt_dyn_info_t *dyn_info, void *ovrr_info,
             uint32_t *data);

#endif /* _BM_SFPT_IF_H_ */
