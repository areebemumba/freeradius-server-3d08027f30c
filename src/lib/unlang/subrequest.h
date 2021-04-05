#pragma once
/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software Foundation,
 *  Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

/**
 * $Id$
 *
 * @file unlang/subrequest.h
 *
 * @copyright 2019 The FreeRADIUS server project
 * @copyright 2021 Arran Cudbard-Bell (a.cudbardb@freeradius.org)
 */
#ifdef __cplusplus
extern "C" {
#endif

#include <freeradius-devel/server/request.h>
#include <freeradius-devel/server/rcode.h>
#include <stdbool.h>

typedef struct {
	bool		enable;				//!< Whether we should store/restore sessions.
	void const	*unique_ptr;			//!< Session unique ptr identifier.
	int		unique_int;			//!< Session unique int identifier.
} unlang_subrequest_session_t;

int		unlang_subrequest_child_detach(request_t *request);

int		unlang_subrequest_child_push(rlm_rcode_t *out, request_t *child,
					     unlang_subrequest_session_t const *session,
					     bool top_frame);

int		unlang_subrequest_child_push_and_detach(request_t *child);

#ifdef __cplusplus
}
#endif