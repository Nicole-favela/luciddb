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

#ifndef Fennel_TracingTupleStream_Included
#define Fennel_TracingTupleStream_Included

#include "fennel/xo/SingleInputTupleStream.h"
#include "fennel/tuple/TupleAccessor.h"
#include "fennel/tuple/TupleData.h"
#include "fennel/tuple/TuplePrinter.h"
#include "fennel/common/TraceSource.h"
#include "fennel/common/ByteInputStream.h"

FENNEL_BEGIN_NAMESPACE

/**
 * TracingTupleStream traces the tuples produced by an underlying input stream.
 */
class TracingTupleStream :
    public SingleInputTupleStream, private ByteInputStream
{
    TupleAccessor tupleAccessor;
    TupleData tupleData;
    TuplePrinter tuplePrinter;
    
    // implement ByteInputStream
    virtual void readNextBuffer();
    
public:
    virtual void prepare(TupleStreamParams const &params);
    virtual ByteInputStream &getProducerResultStream();
    virtual BufferProvision getResultBufferProvision() const;
    virtual BufferProvision getInputBufferRequirement() const;
    virtual ExecutionStream *getImpl();
};

FENNEL_END_NAMESPACE

#endif

// End TracingTupleStream.h