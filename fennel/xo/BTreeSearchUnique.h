/*
// $Id$
// Fennel is a library of data storage and processing components.
// Copyright (C) 2005-2005 The Eigenbase Project
// Copyright (C) 2005-2005 Disruptive Tech
// Copyright (C) 2005-2005 LucidEra, Inc.
// Portions Copyright (C) 1999-2005 John V. Sichi
//
// This program is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by the Free
// Software Foundation; either version 2 of the License, or (at your option)
// any later version approved by The Eigenbase Project.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef Fennel_BTreeSearchUnique_Included
#define Fennel_BTreeSearchUnique_Included

#include "fennel/xo/BTreeSearch.h"

FENNEL_BEGIN_NAMESPACE

/**
 * BTreeSearchUnique is a specialization of BTreeSearch for the case where
 * it is known that each search is guaranteed to find at most one match.
 */
class BTreeSearchUnique : public BTreeSearch
{
public:
    virtual bool writeResultToConsumerBuffer(
        ByteOutputStream &resultOutputStream);
};

FENNEL_END_NAMESPACE

#endif

// End BTreeSearchUnique.h