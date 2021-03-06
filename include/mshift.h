/*
 * This file is part of the GROMACS molecular simulation package.
 *
 * Copyright (c) 1991-2000, University of Groningen, The Netherlands.
 * Copyright (c) 2001-2004, The GROMACS development team,
 * check out http://www.gromacs.org for more information.
 * Copyright (c) 2012,2013, by the GROMACS development team, led by
 * David van der Spoel, Berk Hess, Erik Lindahl, and including many
 * others, as listed in the AUTHORS file in the top-level source
 * directory and at http://www.gromacs.org.
 *
 * GROMACS is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1
 * of the License, or (at your option) any later version.
 *
 * GROMACS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with GROMACS; if not, see
 * http://www.gnu.org/licenses, or write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA.
 *
 * If you want to redistribute modifications to GROMACS, please
 * consider that scientific software is very special. Version
 * control is crucial - bugs must be traceable. We will be happy to
 * consider code for inclusion in the official distribution, but
 * derived work must not be called official GROMACS. Details are found
 * in the README & COPYING files - if they are missing, get the
 * official version at http://www.gromacs.org.
 *
 * To help us fund GROMACS development, we humbly ask that you cite
 * the research papers on the package. Check out http://www.gromacs.org.
 */

#ifndef _mshift_h
#define _mshift_h
#include "visibility.h"
#include "typedefs.h"

#ifdef __cplusplus
extern "C" {
#endif

GMX_LIBGMX_EXPORT
t_graph *mk_graph(FILE *fplog,
                  t_idef *idef, int at_start, int at_end,
                  gmx_bool bShakeOnly, gmx_bool bSettle);
/* Build a graph from an idef description. The graph can be used
 * to generate mol-shift indices.
 * at_start and at_end should coincide will molecule boundaries,
 * for the whole system this is simply 0 and natoms.
 * If bShakeOnly, only the connections in the shake list are used.
 * If bSettle && bShakeOnly the settles are used too.
 */

GMX_LIBGMX_EXPORT
void mk_graph_ilist(FILE *fplog,
                    t_ilist *ilist, int at_start, int at_end,
                    gmx_bool bShakeOnly, gmx_bool bSettle,
                    t_graph *g);
/* As mk_graph, but takes t_ilist iso t_idef and does not allocate g */


GMX_LIBGMX_EXPORT
void done_graph(t_graph *g);
/* Free the memory in g */

GMX_LIBGMX_EXPORT
void p_graph(FILE *log, const char *title, t_graph *g);
/* Print a graph to log */

GMX_LIBGMX_EXPORT
void mk_mshift(FILE *log, t_graph *g, int ePBC, matrix box, rvec x[]);
/* Calculate the mshift codes, based on the connection graph in g. */

GMX_LIBGMX_EXPORT
void shift_x(t_graph *g, matrix box, rvec x[], rvec x_s[]);
/* Add the shift vector to x, and store in x_s (may be same array as x) */

GMX_LIBGMX_EXPORT
void shift_self(t_graph *g, matrix box, rvec x[]);
/* Id. but in place */

GMX_LIBGMX_EXPORT
void unshift_x(t_graph *g, matrix box, rvec x[], rvec x_s[]);
/* Subtract the shift vector from x_s, and store in x (may be same array) */

GMX_LIBGMX_EXPORT
void unshift_self(t_graph *g, matrix box, rvec x[]);
/* Id, but in place */

#ifdef __cplusplus
}
#endif

#endif  /* _mshift_h */
