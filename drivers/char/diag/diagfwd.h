/* Copyright (c) 2008-2012, Code Aurora Forum. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef DIAGFWD_H
#define DIAGFWD_H

#define NO_PROCESS	0
#define NON_APPS_PROC	-1

#define CHK_OVERFLOW(bufStart, start, end, length) \
	((((bufStart) <= (start)) && ((end) - (start) >= (length))) ? 1 : 0)

void diagfwd_init(void);
void diagfwd_exit(void);
void diag_process_hdlc(void *data, unsigned len);
void diag_smd_send_req(struct diag_smd_info *smd_info);
void diag_usb_legacy_notifier(void *, unsigned, struct diag_request *);
long diagchar_ioctl(struct file *, unsigned int, unsigned long);
int diag_device_write(void *, int, struct diag_request *);
int mask_request_validate(unsigned char mask_buf[]);
void diag_clear_reg(int);
int chk_config_get_id(void);
int chk_apps_only(void);
int chk_apps_master(void);
int chk_polling_response(void);
void diag_update_userspace_clients(unsigned int type);
void diag_update_sleeping_process(int process_id, int data_type);
void encode_rsp_and_send(int buf_length);
void diag_smd_notify(void *ctxt, unsigned event);
int diag_smd_constructor(struct diag_smd_info *smd_info, int peripheral,
			 int type);
void diag_smd_destructor(struct diag_smd_info *smd_info);
/* State for diag forwarding */
#ifdef CONFIG_DIAG_OVER_USB
int diagfwd_connect(void);
int diagfwd_disconnect(void);
#endif
extern int diag_debug_buf_idx;
extern unsigned char diag_debug_buf[1024];
extern struct platform_driver msm_diag_dci_driver;
#endif
