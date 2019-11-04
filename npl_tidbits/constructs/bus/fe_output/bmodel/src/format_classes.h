/*
 * SCRIPT GENERATED FILE, DO NOT MODIFY
*/

#ifndef _FORMAT_CLASSES
#define _FORMAT_CLASSES

#include <stdlib.h>
#include "bit_types.h"
#include "base_classes.h"

class packet_field_bus_t;
class obj_bus_t;
class ccbi_t;
class ccbe_t;
class control_id_t;
class egr_obj_bus_t;
class aux_bus_t;
class time_bus_t;

class packet_field_bus_t {
public:
    _8bits src_ipv4_address_byte0;
    _8bits src_ipv4_address_byte1;
    _32bits src_ipv4_address;
    _8bits dst_ipv4_address_byte1;
    _8bits dst_ipv4_address_byte0;
    _32bits dst_ipv4_address;

    packet_field_bus_t(void);
    ~packet_field_bus_t(void);

    void set_src_ipv4_address_byte0(_8bits, int, int);
    void set_src_ipv4_address_byte1(_8bits, int, int);
    void set_src_ipv4_address(_32bits, int, int);
    void set_dst_ipv4_address_byte1(_8bits, int, int);
    void set_dst_ipv4_address_byte0(_8bits, int, int);
    void set_dst_ipv4_address(_32bits, int, int);

    void set_resetval(void);
    void set_randval(void);
    void print(void);
    int compare(packet_field_bus_t *ref, packet_field_bus_t *ref_mask);
    void deep_copy(packet_field_bus_t *ref);
    void unpack_data(uint32_t *_data, int offset = 0);
    void pack_data(uint32_t *_data, int offset = 0);
    int minbit();
    int maxbit();

};

class obj_bus_t {
public:
    _2bits port_type_cfg;
    _7bits port_num;
    _8bits dst_modid;
    _7bits dst_port;

    obj_bus_t(void);
    ~obj_bus_t(void);

    void set_port_type_cfg(_2bits, int, int);
    void set_port_num(_7bits, int, int);
    void set_dst_modid(_8bits, int, int);
    void set_dst_port(_7bits, int, int);

    void set_resetval(void);
    void set_randval(void);
    void print(void);
    int compare(obj_bus_t *ref, obj_bus_t *ref_mask);
    void deep_copy(obj_bus_t *ref);
    void unpack_data(uint32_t *_data, int offset = 0);
    void pack_data(uint32_t *_data, int offset = 0);
    int minbit();
    int maxbit();

};

class ccbi_t {
public:
    _128bits l2_pbm;
    _128bits l3_pbm;

    ccbi_t(void);
    ~ccbi_t(void);

    void set_l2_pbm(_128bits, int, int);
    void set_l3_pbm(_128bits, int, int);

    void set_resetval(void);
    void set_randval(void);
    void print(void);
    int compare(ccbi_t *ref, ccbi_t *ref_mask);
    void deep_copy(ccbi_t *ref);
    void unpack_data(uint32_t *_data, int offset = 0);
    void pack_data(uint32_t *_data, int offset = 0);
    int minbit();
    int maxbit();

};

class ccbe_t {
public:
    _7bits dst_port;

    ccbe_t(void);
    ~ccbe_t(void);

    void set_dst_port(_7bits, int, int);

    void set_resetval(void);
    void set_randval(void);
    void print(void);
    int compare(ccbe_t *ref, ccbe_t *ref_mask);
    void deep_copy(ccbe_t *ref);
    void unpack_data(uint32_t *_data, int offset = 0);
    void pack_data(uint32_t *_data, int offset = 0);
    int minbit();
    int maxbit();

};

class control_id_t {
public:
    _4bits otpid_enable;
    _1bit ts_enable;

    control_id_t(void);
    ~control_id_t(void);

    void set_otpid_enable(_4bits, int, int);
    void set_ts_enable(_1bit, int, int);

    void set_resetval(void);
    void set_randval(void);
    void print(void);
    int compare(control_id_t *ref, control_id_t *ref_mask);
    void deep_copy(control_id_t *ref);
    void unpack_data(uint32_t *_data, int offset = 0);
    void pack_data(uint32_t *_data, int offset = 0);
    int minbit();
    int maxbit();

};

class egr_obj_bus_t {
public:
    _8bits dst_modid;
    _7bits dst_port;
    _7bits ing_port;
    _16bits ingress_timestamp;

    egr_obj_bus_t(void);
    ~egr_obj_bus_t(void);

    void set_dst_modid(_8bits, int, int);
    void set_dst_port(_7bits, int, int);
    void set_ing_port(_7bits, int, int);
    void set_ingress_timestamp(_16bits, int, int);

    void set_resetval(void);
    void set_randval(void);
    void print(void);
    int compare(egr_obj_bus_t *ref, egr_obj_bus_t *ref_mask);
    void deep_copy(egr_obj_bus_t *ref);
    void unpack_data(uint32_t *_data, int offset = 0);
    void pack_data(uint32_t *_data, int offset = 0);
    int minbit();
    int maxbit();

};

class aux_bus_t {
public:
    _16bits drop_vector;

    aux_bus_t(void);
    ~aux_bus_t(void);

    void set_drop_vector(_16bits, int, int);

    void set_resetval(void);
    void set_randval(void);
    void print(void);
    int compare(aux_bus_t *ref, aux_bus_t *ref_mask);
    void deep_copy(aux_bus_t *ref);
    void unpack_data(uint32_t *_data, int offset = 0);
    void pack_data(uint32_t *_data, int offset = 0);
    int minbit();
    int maxbit();

};

class time_bus_t {
public:
    _16bits currenttime;

    time_bus_t(void);
    ~time_bus_t(void);

    void set_currenttime(_16bits, int, int);

    void set_resetval(void);
    void set_randval(void);
    void print(void);
    int compare(time_bus_t *ref, time_bus_t *ref_mask);
    void deep_copy(time_bus_t *ref);
    void unpack_data(uint32_t *_data, int offset = 0);
    void pack_data(uint32_t *_data, int offset = 0);
    int minbit();
    int maxbit();

};

#endif
