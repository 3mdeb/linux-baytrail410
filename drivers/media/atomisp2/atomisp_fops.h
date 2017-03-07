/*
 * Support for Medifield PNW Camera Imaging ISP subsystem.
 *
 * Copyright (c) 2010 Intel Corporation. All Rights Reserved.
 *
 * Copyright (c) 2010 Silicon Hive www.siliconhive.com.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License version
 * 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *
 */

#ifndef	__ATOMISP_FOPS_H__
#define	__ATOMISP_FOPS_H__

#include "sh_css_legacy.h"

#define MAX_LOAD_FIRMWARE_TIMEOUTS 20
static DECLARE_WAIT_QUEUE_HEAD(atomisp_wait_queue);
static DECLARE_WAIT_QUEUE_HEAD(atomisp_switch_wait_queue);

extern struct ia_css_env css_env;

int atomisp_q_video_buffers_to_css(struct atomisp_sub_device *isp_subdev,
			     struct atomisp_video_pipe *pipe,
			     enum ia_css_buffer_type css_buf_type,
			     enum ia_css_pipe_id css_pipe_id, bool streamoff);

int atomisp_q_s3a_buffers_to_css(struct atomisp_sub_device *isp_subdev,
			   enum ia_css_pipe_id css_pipe_id, bool streamoff);

int atomisp_q_dis_buffers_to_css(struct atomisp_sub_device *isp_subdev,
			   enum ia_css_pipe_id css_pipe_id, bool streamoff);

int atomisp_dev_init_struct(struct atomisp_device *isp);
int atomisp_subdev_init_struct(struct atomisp_sub_device *isp_subdev);

int atomisp_subdev_streaming_count(struct atomisp_device *isp);
void atomisp_control_irq_sof(struct atomisp_device * isp);

unsigned int atomisp_subdev_users(struct atomisp_sub_device *isp_subdev);
unsigned int atomisp_dev_users(struct atomisp_device *isp);

/*
 * Memory help functions for image frame and private parameters
 */

int atomisp_file_mmap(struct file *file, struct vm_area_struct *vma);

int atomisp_qbuffers_to_css(struct atomisp_sub_device *isp_subdev, bool streamoff);

extern const struct v4l2_file_operations atomisp_fops;

#endif /* __ATOMISP_FOPS_H__ */