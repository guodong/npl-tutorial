/*
 * $Copyright: (c) 2018 Broadcom Corp.
 * All Rights Reserved.$
 * File:     bm_field.h
 * Purpose:  Behavior Model field header
 *
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated
 * Edits to this file will be lost when it is regenerated.
 *
 */

#ifndef _BM_FIELD_H_
#define _BM_FIELD_H_

#include "include_libs.h"

/*
 * \brief Get field (little endian word order).
 *
 * Extract field from multi-word entry in little endian order.
 *
 * \param [in] entbuf Entry buffer.
 * \param [in] sbit Start bit of field.
 * \param [in] ebit End bit of field.
 * \param [out] fbuf Field buffer for output.
 *
 * \return Pointer to \c fbuf.
 */
extern uint32_t *
bm_field_get(const uint32_t *entbuf,
             int sbit, int ebit, uint32_t *fbuf);

/*!
 * \brief Set field (little endian word order).
 *
 * Encode field into multi-word entry in little endian order.
 *
 * \param [in] entbuf Entry buffer.
 * \param [in] sbit Start bit of field.
 * \param [in] ebit End bit of field.
 * \param [in] fbuf Field buffer.
 *
 * \return Nothing.
 */
extern void
bm_field_set(uint32_t *entbuf,
             int sbit, int ebit, uint32_t *fbuf);
 
#endif /* _BM_FIELD_H_ */
