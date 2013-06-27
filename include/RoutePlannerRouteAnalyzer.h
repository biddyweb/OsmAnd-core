/**
* @file
*
* @section LICENSE
*
* OsmAnd - Android navigation software based on OSM maps.
* Copyright (C) 2010-2013  OsmAnd Authors listed in AUTHORS file
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

#ifndef __ROUTE_PLANNER_ANALYZER__H_
#define __ROUTE_PLANNER_ANALYZER__H_
#include <OsmAndCore.h>
#include <RoutePlannerContext.h>
namespace OsmAnd {

    class OSMAND_CORE_API RoutePlannerAnalyzer
    {
    public:
        static bool prepareResult(OsmAnd::RoutePlannerContext::CalculationContext* context,
            std::shared_ptr<RoutePlannerContext::RouteCalculationSegment> finalSegment,
            QList< std::shared_ptr<RouteSegment> >* outResult,
            bool leftSideNavigation);
        enum {
            MinTurnAngle = 45
        };
        RoutePlannerAnalyzer();

        ~RoutePlannerAnalyzer();
        static void addRouteSegmentToRoute(QVector< std::shared_ptr<RouteSegment> >& route, const std::shared_ptr<RouteSegment>& segment, bool reverse);
        static bool combineTwoSegmentResult(const std::shared_ptr<RouteSegment>& toAdd, const std::shared_ptr<RouteSegment>& previous, bool reverse);
        static bool validateAllPointsConnected(const QVector< std::shared_ptr<RouteSegment> >& route);
        static void splitRoadsAndAttachRoadSegments(OsmAnd::RoutePlannerContext::CalculationContext* context, QVector< std::shared_ptr<RouteSegment> >& route);
        static void calculateTimeSpeedInRoute(OsmAnd::RoutePlannerContext::CalculationContext* context, QVector< std::shared_ptr<RouteSegment> >& route);
        static void printRouteInfo(QVector< std::shared_ptr<RouteSegment> >& route);
        static void addTurnInfoToRoute( bool leftSideNavigation, QVector< std::shared_ptr<RouteSegment> >& route );
        static void attachRouteSegments(
            OsmAnd::RoutePlannerContext::CalculationContext* context,
            QVector< std::shared_ptr<RouteSegment> >& route,
            const QVector< std::shared_ptr<RouteSegment> >::iterator& itSegment,
            uint32_t pointIdx,
            bool isIncrement);

    };

} // namespace OsmAnd

#endif // __ROUTE_PLANNER_ANALYZER__H_
