/*
// $Id$
// Farrago is an extensible data management system.
// Copyright (C) 2005-2005 The Eigenbase Project
// Copyright (C) 2005-2005 Disruptive Tech
// Copyright (C) 2005-2005 Red Square, Inc.
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
package net.sf.farrago.rng;

import net.sf.farrago.parser.*;
import net.sf.farrago.rng.parserimpl.*;

import java.io.*;

/**
 * FarragoRngParser is the public wrapper for the JavaCC-generated
 * RngParser.
 *
 * @author John V. Sichi
 * @version $Id$
 */
public class FarragoRngParser extends FarragoAbstractParser
{
    private static final String jdbcKeywords;

    static 
    {
        RngParser parser = new RngParser(new StringReader(""));
        jdbcKeywords = constructReservedKeywordList(
            RngParserConstants.tokenImage,
            parser);
    }

    // implement FarragoSessionParser
    public String getJdbcKeywords()
    {
        return jdbcKeywords;
    }
    
    // implement FarragoAbstractParser
    protected FarragoAbstractParserImpl newParserImpl(Reader reader)
    {
        return new RngParser(reader);
    }
}

// End FarragoRngParser.java