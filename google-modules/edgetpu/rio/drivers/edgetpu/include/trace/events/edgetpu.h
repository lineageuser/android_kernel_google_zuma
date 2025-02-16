/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Trace events for edgetpu
 *
 * Copyright (c) 2020 Google Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#undef TRACE_SYSTEM
#define TRACE_SYSTEM edgetpu

#if !defined(_TRACE_EDGETPU_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_EDGETPU_H

#include <linux/stringify.h>
#include <linux/tracepoint.h>

#include "../../../edgetpu.h"

#define EDGETPU_TRACE_SYSTEM __stringify(TRACE_SYSTEM)

TRACE_EVENT(edgetpu_map_buffer_start,

	TP_PROTO(struct edgetpu_map_ioctl *ibuf),

	TP_ARGS(ibuf),

	TP_STRUCT__entry(
		__field(__u64, host_address)
		__field(__u64, size)
		__field(edgetpu_map_flag_t, flags)
		__field(__u32, die_index)
	),

	TP_fast_assign(
		__entry->host_address = ibuf->host_address;
		__entry->size = ibuf->size;
		__entry->flags = ibuf->flags;
		__entry->die_index = ibuf->die_index;
	),

	TP_printk("host_address = 0x%llx, size = %llu, flags = 0x%x, die_index = %u",
		__entry->host_address, __entry->size, __entry->flags,
		__entry->die_index)
);

TRACE_EVENT(edgetpu_map_buffer_end,

	TP_PROTO(struct edgetpu_map_ioctl *ibuf),

	TP_ARGS(ibuf),

	TP_STRUCT__entry(
		__field(__u64, host_address)
		__field(__u64, size)
		__field(__u64, device_address)
		__field(edgetpu_map_flag_t, flags)
		__field(__u32, die_index)
	),

	TP_fast_assign(
		__entry->host_address = ibuf->host_address;
		__entry->size = ibuf->size;
		__entry->device_address = ibuf->device_address;
		__entry->flags = ibuf->flags;
		__entry->die_index = ibuf->die_index;
	),

	TP_printk("host_address = 0x%llx, size = %llu, device_address = 0x%llx, flags = 0x%x, die_index = %u",
		__entry->host_address, __entry->size, __entry->device_address,
		__entry->flags, __entry->die_index)
);

TRACE_EVENT(edgetpu_map_dmabuf_start,

	TP_PROTO(struct edgetpu_map_dmabuf_ioctl *ibuf),

	TP_ARGS(ibuf),

	TP_STRUCT__entry(
		__field(__u64, offset)
		__field(__u64, size)
		__field(int, dmabuf_fd)
		__field(edgetpu_map_flag_t, flags)
		__field(__u32, die_index)
	),

	TP_fast_assign(
		__entry->offset = ibuf->offset;
		__entry->size = ibuf->size;
		__entry->dmabuf_fd = ibuf->dmabuf_fd;
		__entry->flags = ibuf->flags;
		__entry->die_index = ibuf->die_index;
	),

	TP_printk("offset = 0x%llx, size = %llu, dmabuf_fd = %d, flags = 0x%x, die_index = %u",
		__entry->offset, __entry->size, __entry->dmabuf_fd,
		__entry->flags, __entry->die_index)
);

TRACE_EVENT(edgetpu_map_dmabuf_end,

	TP_PROTO(struct edgetpu_map_dmabuf_ioctl *ibuf),

	TP_ARGS(ibuf),

	TP_STRUCT__entry(
		__field(__u64, offset)
		__field(__u64, size)
		__field(__u64, device_address)
		__field(int, dmabuf_fd)
		__field(edgetpu_map_flag_t, flags)
		__field(__u32, die_index)
	),

	TP_fast_assign(
		__entry->offset = ibuf->offset;
		__entry->size = ibuf->size;
		__entry->device_address = ibuf->device_address;
		__entry->dmabuf_fd = ibuf->dmabuf_fd;
		__entry->flags = ibuf->flags;
		__entry->die_index = ibuf->die_index;
	),

	TP_printk("offset = 0x%llx, size = %llu, device_address = 0x%llx, dmabuf_fd = %d, flags = 0x%x, die_index = %u",
		__entry->offset, __entry->size, __entry->device_address,
		__entry->dmabuf_fd, __entry->flags, __entry->die_index)
);

TRACE_EVENT(edgetpu_acquire_wakelock_start,

	TP_PROTO(pid_t pid),

	TP_ARGS(pid),

	TP_STRUCT__entry(
		__field(pid_t, pid)
	),

	TP_fast_assign(
		__entry->pid = pid;
	),

	TP_printk("pid = %d", __entry->pid)
);

TRACE_EVENT(edgetpu_acquire_wakelock_end,

	TP_PROTO(pid_t pid, int count, int ret),

	TP_ARGS(pid, count, ret),

	TP_STRUCT__entry(
		__field(pid_t, pid)
		__field(int, count)
		__field(int, ret)
	),

	TP_fast_assign(
		__entry->pid = pid;
		__entry->count = count;
		__entry->ret = ret;
	),

	TP_printk("pid = %d, req_count = %d, ret = %d", __entry->pid, __entry->count, __entry->ret)
);

TRACE_EVENT(edgetpu_release_wakelock_start,

	TP_PROTO(pid_t pid),

	TP_ARGS(pid),

	TP_STRUCT__entry(
		__field(pid_t, pid)
	),

	TP_fast_assign(
		__entry->pid = pid;
	),

	TP_printk("pid = %d", __entry->pid)
);

TRACE_EVENT(edgetpu_release_wakelock_end,

	TP_PROTO(pid_t pid, int count),

	TP_ARGS(pid, count),

	TP_STRUCT__entry(
		__field(pid_t, pid)
		__field(int, count)
	),

	TP_fast_assign(
		__entry->pid = pid;
		__entry->count = count;
	),

	TP_printk("pid = %d, req_count = %d", __entry->pid, __entry->count)
);

#endif /* _TRACE_EDGETPU_H */

/* This part must be outside protection */
#include <trace/define_trace.h>
