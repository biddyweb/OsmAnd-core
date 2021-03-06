#ifndef _OSMAND_CORE_MAP_STYLE_EVALUATION_RESULT_H_
#define _OSMAND_CORE_MAP_STYLE_EVALUATION_RESULT_H_

#include <OsmAndCore/stdlib_common.h>
#include <cstdarg>
#include <utility>

#include <OsmAndCore/QtExtensions.h>
#include <QVector>
#include <QVariant>

#include <OsmAndCore.h>
#include <OsmAndCore/Common.h>
#include <OsmAndCore/Map/MapCommonTypes.h>
#include <OsmAndCore/Map/ResolvedMapStyle.h>

namespace OsmAnd
{
    class OSMAND_CORE_API MapStyleEvaluationResult Q_DECL_FINAL
    {
    private:
    protected:
        QVector<QVariant> _storage;

    public:
        MapStyleEvaluationResult(const int size = 0);
        MapStyleEvaluationResult(const MapStyleEvaluationResult& that);
#ifdef Q_COMPILER_RVALUE_REFS
        MapStyleEvaluationResult(MapStyleEvaluationResult&& that);
#endif // Q_COMPILER_RVALUE_REFS
        ~MapStyleEvaluationResult();

        MapStyleEvaluationResult& operator=(const MapStyleEvaluationResult& that);
#ifdef Q_COMPILER_RVALUE_REFS
        MapStyleEvaluationResult& operator=(MapStyleEvaluationResult&& that);
#endif // Q_COMPILER_RVALUE_REFS

        bool contains(const IMapStyle::ValueDefinitionId valueDefId) const;

        void setValue(const IMapStyle::ValueDefinitionId valueDefId, const QVariant& value);
        void setBooleanValue(const IMapStyle::ValueDefinitionId valueDefId, const bool& value);
        void setIntegerValue(const IMapStyle::ValueDefinitionId valueDefId, const int& value);
        void setIntegerValue(const IMapStyle::ValueDefinitionId valueDefId, const unsigned int& value);
        void setFloatValue(const IMapStyle::ValueDefinitionId valueDefId, const float& value);
        void setStringValue(const IMapStyle::ValueDefinitionId valueDefId, const QString& value);
    
        bool getValue(const IMapStyle::ValueDefinitionId valueDefId, QVariant& outValue) const;
        bool getBooleanValue(const IMapStyle::ValueDefinitionId valueDefId, bool& outValue) const;
        bool getIntegerValue(const IMapStyle::ValueDefinitionId valueDefId, int& outValue) const;
        bool getIntegerValue(const IMapStyle::ValueDefinitionId valueDefId, unsigned int& outValue) const;
        bool getFloatValue(const IMapStyle::ValueDefinitionId valueDefId, float& outValue) const;
        bool getStringValue(const IMapStyle::ValueDefinitionId valueDefId, QString& outValue) const;

        QHash<IMapStyle::ValueDefinitionId, QVariant> getValues() const;

        void reset();
        void clear();
        bool isEmpty() const;

        typedef std::pair<IMapStyle::ValueDefinitionId, QVariant> PackedResultEntry;
        typedef QList<PackedResultEntry> PackedResult;
        void pack(PackedResult& packedResult) const;
    };
}

#endif // !defined(_OSMAND_CORE_MAP_STYLE_EVALUATION_RESULT_H_)
