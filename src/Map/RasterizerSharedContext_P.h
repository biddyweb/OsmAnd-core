/**
* @file
*
* @section LICENSE
*
* OsmAnd - Android navigation software based on OSM maps.
* Copyright (C) 2010-2014  OsmAnd Authors listed in AUTHORS file
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.

* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _OSMAND_CORE_RASTERIZER_SHARED_CONTEXT_P_H_
#define _OSMAND_CORE_RASTERIZER_SHARED_CONTEXT_P_H_

#include <OsmAndCore/stdlib_common.h>
#include <array>

#include <OsmAndCore/QtExtensions.h>
#include <QtGlobal>

#include "OsmAndCore.h"
#include "Rasterizer_P.h"
#include "SharedResourcesContainer.h"

namespace OsmAnd
{
    class Rasterizer_P;
    class RasterizerContext;
    class RasterizerContext_P;

    class RasterizerSharedContext;
    class RasterizerSharedContext_P
    {
    private:
    protected:
        RasterizerSharedContext_P(RasterizerSharedContext* const owner);

        RasterizerSharedContext* const _owner;

        std::array< SharedResourcesContainer<uint64_t, const Rasterizer_P::PrimitivesGroup>, ZoomLevelsCount> _sharedPrimitivesGroups;
        std::array< SharedResourcesContainer<uint64_t, const Rasterizer_P::SymbolsGroup>, ZoomLevelsCount> _sharedSymbolGroups;
    public:
        virtual ~RasterizerSharedContext_P();

    friend class OsmAnd::RasterizerSharedContext;
    friend class OsmAnd::Rasterizer_P;
    friend class OsmAnd::RasterizerContext;
    friend class OsmAnd::RasterizerContext_P;
    };

} // namespace OsmAnd

#endif // _OSMAND_CORE_RASTERIZER_SHARED_CONTEXT_P_H_