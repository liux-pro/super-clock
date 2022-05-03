/* generated common header file - do not edit */
#ifndef COMMON_DATA_H_
#define COMMON_DATA_H_
#include <stdint.h>
#include "bsp_api.h"
#include "rm_tinycrypt_port.h"
#include "tinycrypt/cbc_mode.h"
#include "tinycrypt/ccm_mode.h"
#include "tinycrypt/cmac_mode.h"
#include "tinycrypt/constants.h"
#include "tinycrypt/ctr_mode.h"
#include "tinycrypt/ctr_prng.h"
#include "tinycrypt/ecc_dh.h"
#include "tinycrypt/ecc_dsa.h"
#include "tinycrypt/ecc_platform_specific.h"
#include "tinycrypt/ecc.h"
#include "tinycrypt/hmac_prng.h"
#include "tinycrypt/hmac.h"
#include "tinycrypt/sha256.h"
#include "tinycrypt/utils.h"
#include "r_ioport.h"
#include "bsp_pin_cfg.h"
FSP_HEADER
/* IOPORT Instance */
extern const ioport_instance_t g_ioport;

/* IOPORT control structure. */
extern ioport_instance_ctrl_t g_ioport_ctrl;
void g_common_init(void);
FSP_FOOTER
#endif /* COMMON_DATA_H_ */
