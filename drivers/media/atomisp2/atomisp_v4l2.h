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

#ifndef __ATOMISP_V4L2_H__
#define __ATOMISP_V4L2_H__

#include "atomisp_internal.h"

struct atomisp_video_pipe;
struct v4l2_device;

extern void __iomem *atomisp_io_base;

int firmware_load_helper(const struct firmware **firmware, struct atomisp_device *isp);
int load_ISP_firmware(void *void_isp);


int atomisp_video_init(struct atomisp_video_pipe *video, const char *name);
void atomisp_video_unregister(struct atomisp_video_pipe *video);
int atomisp_video_register(struct atomisp_video_pipe *video,
	struct v4l2_device *vdev);

#endif /* __ATOMISP_V4L2_H__ */