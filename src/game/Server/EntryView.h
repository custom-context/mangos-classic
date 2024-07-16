#pragma once

#include "DBCStructure.h"

#include <array>
#include <string_view>
#include <tuple>

namespace entry::view {

template<class TableEntry, class View>
class BaseEntryView {
public:
    static_assert(std::is_same_v<TableEntry, std::decay_t<TableEntry>>);
    using DBCStruct = TableEntry;

    explicit BaseEntryView(): m_dbcHandler{nullptr} {};
    explicit BaseEntryView(const DBCStruct* dbcHandler): m_dbcHandler{dbcHandler} {};

    auto const* operator->() const {
        return static_cast<View const*>(this);
    }

    operator bool() const noexcept {
        return !!m_dbcHandler;
    }

protected:
    const DBCStruct* GetRaw() const {
        return m_dbcHandler;
    }

    const DBCStruct* m_dbcHandler;
};

class AreaView: public BaseEntryView<AreaTableEntry, AreaView>
{
public:
    using BaseEntryView<AreaTableEntry, AreaView>::BaseEntryView;

    auto GetID() const noexcept {
        return GetRaw()->ID;
    }

    auto GetMapID() const noexcept {
        return GetRaw()->mapid;
    }

    auto GetZone() const noexcept {
        return GetRaw()->zone;
    }

    auto GetExploreFlag() const noexcept {
        return GetRaw()->exploreFlag;
    }

    auto GetFlags() const noexcept {
        return GetRaw()->flags;
    }

    auto GetAreaLevel() const noexcept {
        return GetRaw()->area_level;
    }

    constexpr static auto GetAreaNamesSize() noexcept {
        return std::extent_v<decltype(std::declval<BaseEntryView::DBCStruct>().area_name)>;
    }

    auto GetDefaultAreaName() const noexcept {
        return GetRaw()->area_name[0u];
    }

    auto GetAreaName(size_t idx) const noexcept {
        if (idx < GetAreaNamesSize()) {
            return GetRaw()->area_name[idx];
        }
        return GetDefaultAreaName();
    }

    auto GetTeam() const noexcept {
        return GetRaw()->team;
    }

    auto GetLiquidTypeOverride() const noexcept {
        return GetRaw()->LiquidTypeOverride;
    }
};

class ChatChannelView: public BaseEntryView<ChatChannelsEntry, ChatChannelView>
{
public:
    using BaseEntryView<ChatChannelsEntry, ChatChannelView>::BaseEntryView;

    auto GetChannelID() const noexcept {
        return GetRaw()->ChannelID;
    }

    auto GetFlags() const noexcept {
        return GetRaw()->flags;
    }

    constexpr static auto GetPatternsSize() noexcept {
        return std::extent_v<decltype(std::declval<BaseEntryView::DBCStruct>().pattern)>;
    }

    auto GetDefaultPattern() const noexcept {
        return GetRaw()->pattern[0u];
    }

    auto GetPattern(size_t idx) const noexcept {
        if (idx < GetPatternsSize()) {
            return GetRaw()->pattern[idx];
        }
        return GetDefaultPattern();
    }
};

class CharacterClassView: public BaseEntryView<ChrClassesEntry, CharacterClassView>
{
public:
    using BaseEntryView<ChrClassesEntry, CharacterClassView>::BaseEntryView;

    auto GetClassID() const noexcept {
        return GetRaw()->ClassID;
    }

    auto GetPowerType() const noexcept {
        return GetRaw()->powerType;
    }

    constexpr static auto GetNamesSize() noexcept {
        return std::extent_v<decltype(std::declval<BaseEntryView::DBCStruct>().name)>;
    }

    auto GetDefaultName() const noexcept {
        return GetRaw()->name[0u];
    }

    auto GetName(size_t idx) const noexcept {
        if (idx < GetNamesSize()) {
            return GetRaw()->name[idx];
        }
        return GetDefaultName();
    }

    auto GetSpellFamily() const noexcept {
        return GetRaw()->spellfamily;
    }
};

class CharacterRaceView: public BaseEntryView<ChrRacesEntry, CharacterRaceView>
{
public:
    using BaseEntryView<ChrRacesEntry, CharacterRaceView>::BaseEntryView;

    auto GetRaceID() const noexcept {
        return GetRaw()->RaceID;
    }

    auto GetFactionID() const noexcept {
        return GetRaw()->FactionID;
    }

    auto GetMaleModel() const noexcept {
        return GetRaw()->model_m;
    }

    auto GetFemaleModel() const noexcept {
        return GetRaw()->model_f;
    }

    auto GetTeamID() const noexcept {
        return GetRaw()->TeamID;
    }

    auto GetStartingTaxiMask() const noexcept {
        return GetRaw()->startingTaxiMask;
    }

    auto GetCinematicSequence() const noexcept {
        return GetRaw()->CinematicSequence;
    }

    constexpr static auto GetNamesSize() noexcept {
        return std::extent_v<decltype(std::declval<BaseEntryView::DBCStruct>().name)>;
    }

    auto GetDefaultName() const noexcept {
        return GetRaw()->name[0u];
    }

    auto GetName(size_t idx) const noexcept {
        if (idx < GetNamesSize()) {
            return GetRaw()->name[idx];
        }
        return GetDefaultName();
    }
};

class CreatureFamilyView: public BaseEntryView<CreatureFamilyEntry, CreatureFamilyView>
{
public:
    using BaseEntryView<CreatureFamilyEntry, CreatureFamilyView>::BaseEntryView;

    auto GetID() const noexcept {
        return GetRaw()->ID;
    }

    auto GetMinScale() const noexcept {
        return GetRaw()->minScale;
    }

    auto GetMinScaleLevel() const noexcept {
        return GetRaw()->minScaleLevel;
    }

    auto GetMaxScale() const noexcept {
        return GetRaw()->maxScale;
    }

    auto GetMaxScaleLevel() const noexcept {
        return GetRaw()->maxScaleLevel;
    }

    auto GetSkillLine() const noexcept {
        return std::make_tuple(GetRaw()->skillLine[0u], GetRaw()->skillLine[1u]);
    }

    auto GetPetFoodMask() const noexcept {
        return GetRaw()->petFoodMask;
    }

    constexpr static auto GetNamesSize() noexcept {
        return std::extent_v<decltype(std::declval<BaseEntryView::DBCStruct>().Name)>;
    }

    auto GetDefaultName() const noexcept {
        return GetRaw()->Name[0u];
    }

    auto GetName(size_t idx) const noexcept {
        if (idx < GetNamesSize()) {
            return GetRaw()->Name[idx];
        }
        return GetDefaultName();
    }
};

class DungeonEncounterView: public BaseEntryView<DungeonEncounterEntry, DungeonEncounterView>
{
public:
    using BaseEntryView<DungeonEncounterEntry, DungeonEncounterView>::BaseEntryView;

    auto GetID() const noexcept {
        return GetRaw()->Id;
    }

    auto GetMapID() const noexcept {
        return GetRaw()->mapId;
    }

    auto GetDifficulty() const noexcept {
        return GetRaw()->Difficulty;
    }

    auto GetEncounterData() const noexcept {
        return GetRaw()->encounterData;
    }

    auto GetEncounterIndex() const noexcept {
        return GetRaw()->encounterIndex;
    }

    auto GetCompleteWorldStateID() const noexcept {
        return GetRaw()->CompleteWorldStateID;
    }

    constexpr static auto GetEncounterNamesSize() noexcept {
        return std::extent_v<decltype(std::declval<BaseEntryView::DBCStruct>().encounterName)>;
    }

    auto GetDefaultEncounterName() const noexcept {
        return GetRaw()->encounterName[0u];
    }

    auto GetEncounterName(size_t idx) const noexcept {
        if (idx < GetEncounterNamesSize()) {
            return GetRaw()->encounterName[idx];
        }
        return GetDefaultEncounterName();
    }

    auto GetNameLangFlags() const noexcept {
        return GetRaw()->nameLangFlags;
    }

    auto GetSpellIconID() const noexcept {
        return GetRaw()->spellIconID;
    }
};

class FactionView: public BaseEntryView<FactionEntry, FactionView>
{
public:
    using BaseEntryView<FactionEntry, FactionView>::BaseEntryView;

    auto GetID() const noexcept {
        return GetRaw()->ID;
    }

    auto GetReputationIndex() const noexcept {
        return GetRaw()->reputationListID;
    }

    auto GetReputationRaceMask() const noexcept {
        return GetRaw()->BaseRepRaceMask;
    }

    auto GetReputationClassMask() const noexcept {
        return GetRaw()->BaseRepClassMask;
    }

    auto GetReputationBase() const noexcept {
        return GetRaw()->BaseRepValue;
    }

    auto GetReputationFlags() const noexcept {
        return GetRaw()->ReputationFlags;
    }

    auto GetTeam() const noexcept {
        return GetRaw()->team;
    }

    constexpr static auto GetNamesSize() noexcept {
        return std::extent_v<decltype(std::declval<BaseEntryView::DBCStruct>().name)>;
    }

    auto GetDefaultName() const noexcept {
        return GetRaw()->name[0u];
    }

    auto GetName(size_t idx) const noexcept {
        if (idx < GetNamesSize()) {
            return GetRaw()->name[idx];
        }
        return GetDefaultName();
    }

    auto GetIndexFitTo(uint32 raceMask, uint32 classMask) const {
        return GetRaw()->GetIndexFitTo(raceMask, classMask);
    }

    auto HasReputation() const {
        return GetRaw()->HasReputation();
    }
};

class GMSurveyQuestionsView: public BaseEntryView<GMSurveyQuestionsEntry, GMSurveyQuestionsView>
{
public:
    using BaseEntryView<GMSurveyQuestionsEntry, GMSurveyQuestionsView>::BaseEntryView;

    auto GetID() const noexcept {
        return GetRaw()->ID;
    }

    constexpr static auto GetQuestionsSize() noexcept {
        return std::extent_v<decltype(std::declval<BaseEntryView::DBCStruct>().question)>;
    }

    auto GetDefaultQuestion() const noexcept {
        return GetRaw()->question[0u];
    }

    auto GetQuestion(size_t idx) const noexcept {
        if (idx < GetQuestionsSize()) {
            return GetRaw()->question[idx];
        }
        return GetDefaultQuestion();
    }
};

class GMTicketCategoryView: public BaseEntryView<GMTicketCategoryEntry, GMTicketCategoryView>
{
public:
    using BaseEntryView<GMTicketCategoryEntry, GMTicketCategoryView>::BaseEntryView;

    auto GetID() const noexcept {
        return GetRaw()->ID;
    }

    constexpr static auto GetNamesSize() noexcept {
        return std::extent_v<decltype(std::declval<BaseEntryView::DBCStruct>().name)>;
    }

    auto GetDefaultName() const noexcept {
        return GetRaw()->name[0u];
    }

    auto GetName(size_t idx) const noexcept {
        if (idx < GetNamesSize()) {
            return GetRaw()->name[idx];
        }
        return GetDefaultName();
    }
};

class ItemClassView: public BaseEntryView<ItemClassEntry, ItemClassView>
{
public:
    using BaseEntryView<ItemClassEntry, ItemClassView>::BaseEntryView;

    auto GetID() const noexcept {
        return GetRaw()->ID;
    }

    constexpr static auto GetNamesSize() noexcept {
        return std::extent_v<decltype(std::declval<BaseEntryView::DBCStruct>().name)>;
    }

    auto GetDefaultName() const noexcept {
        return GetRaw()->name[0u];
    }

    auto GetName(size_t idx) const noexcept {
        if (idx < GetNamesSize()) {
            return GetRaw()->name[idx];
        }
        return GetDefaultName();
    }
};

class ItemSetView: public BaseEntryView<ItemSetEntry, ItemSetView>
{
public:
    using BaseEntryView<ItemSetEntry, ItemSetView>::BaseEntryView;

    constexpr static auto GetNamesSize() noexcept {
        return std::extent_v<decltype(std::declval<BaseEntryView::DBCStruct>().name)>;
    }

    auto GetDefaultName() const noexcept {
        return GetRaw()->name[0u];
    }

    auto GetName(size_t idx) const noexcept {
        if (idx < GetNamesSize()) {
            return GetRaw()->name[idx];
        }
        return GetDefaultName();
    }

    constexpr static auto GetSpellIDsSize() noexcept {
        return std::extent_v<decltype(std::declval<BaseEntryView::DBCStruct>().spells)>;
    }

    auto GetSpellID(size_t idx) const noexcept {
        assert(idx < GetSpellIDsSize());
        return GetRaw()->spells[idx];
    }

    constexpr static auto GetItemsIDsToSpellTriggersMapSize() noexcept {
        return std::extent_v<decltype(std::declval<BaseEntryView::DBCStruct>().items_to_triggerspell)>;
    }

    auto GetTriggerSpellByItemID(size_t idx) const noexcept {
        assert(idx < GetItemsIDsToSpellTriggersMapSize());
        return GetRaw()->spells[idx];
    }

    auto GetRequiredSkillID() const noexcept {
        return GetRaw()->required_skill_id;
    }

    auto GetRequiredSkillRank() const noexcept {
        return GetRaw()->required_skill_value;
    }
};

class MapView: public BaseEntryView<MapEntry, MapView>
{
public:
    using BaseEntryView<MapEntry, MapView>::BaseEntryView;

    auto GetMapID() const noexcept {
        return GetRaw()->MapID;
    }

    auto GetMapType() const noexcept {
        return GetRaw()->map_type;
    }

    constexpr static auto GetNamesSize() noexcept {
        return std::extent_v<decltype(std::declval<BaseEntryView::DBCStruct>().name)>;
    }

    auto GetDefaultName() const noexcept {
        return GetRaw()->name[0u];
    }

    auto GetName(size_t idx) const noexcept {
        if (idx < GetNamesSize()) {
            return GetRaw()->name[idx];
        }
        return GetDefaultName();
    }

    auto GetLinkedZoneID() const noexcept {
        return GetRaw()->linked_zone;
    }

    auto GetMultimapID() const noexcept {
        return GetRaw()->multimap_id;
    }

    auto IsDungeon() const { return GetRaw()->IsDungeon(); }
    auto IsNonRaidDungeon() const { return GetRaw()->IsNonRaidDungeon(); }
    auto Instanceable() const { return GetRaw()->Instanceable(); }
    auto IsRaid() const { return GetRaw()->IsRaid(); }
    auto IsBattleGround() const { return GetRaw()->IsBattleGround(); }

    auto IsContinent() const { return GetRaw()->IsContinent(); }
};

class SkillLineView: public BaseEntryView<SkillLineEntry, SkillLineView>
{
public:
    using BaseEntryView<SkillLineEntry, SkillLineView>::BaseEntryView;

    auto GetID() const noexcept {
        return GetRaw()->id;
    }

    auto GetCategoryId() const noexcept {
        return GetRaw()->categoryId;
    }

    constexpr static auto GetNamesSize() noexcept {
        return std::extent_v<decltype(std::declval<BaseEntryView::DBCStruct>().name)>;
    }

    auto GetDefaultName() const noexcept {
        return GetRaw()->name[0u];
    }

    auto GetName(size_t idx) const noexcept {
        if (idx < GetNamesSize()) {
            return GetRaw()->name[idx];
        }
        return GetDefaultName();
    }

    auto GetSpellIcon() const noexcept {
        return GetRaw()->spellIcon;
    }
};

class SpellView: public BaseEntryView<SpellEntry, SpellView>
{
public:
    using BaseEntryView<SpellEntry, SpellView>::BaseEntryView;

    auto GetID() const noexcept {
        return GetRaw()->Id;
    }

    auto GetSchool() const noexcept {
        return GetRaw()->School;
    }

    auto GetCategory() const noexcept {
        return GetRaw()->Category;
    }

    auto GetCastUI() const noexcept {
        return GetRaw()->CastUI;
    }

    auto GetDispel() const noexcept {
        return GetRaw()->Dispel;
    }

    auto GetMechanic() const noexcept {
        return GetRaw()->Mechanic;
    }

    auto GetAttributes() const noexcept {
        return GetRaw()->Attributes;
    }

    template<size_t N>
    auto GetAttributesExtensions() const noexcept;
    
    auto GetStances() const noexcept {
        return GetRaw()->Stances;
    }
    
    auto GetStancesNot() const noexcept {
        return GetRaw()->StancesNot;
    }
    
    auto GetTargets() const noexcept {
        return GetRaw()->Targets;
    }
    
    auto GetTargetCreatureType() const noexcept {
        return GetRaw()->TargetCreatureType;
    }
    
    auto GetRequiresSpellFocus() const noexcept {
        return GetRaw()->RequiresSpellFocus;
    }
    
    auto GetCasterAuraState() const noexcept {
        return GetRaw()->CasterAuraState;
    }
    
    auto GetTargetAuraState() const noexcept {
        return GetRaw()->TargetAuraState;
    }
    
    auto GetCastingTimeIndex() const noexcept {
        return GetRaw()->CastingTimeIndex;
    }
    
    auto GetRecoveryTime() const noexcept {
        return GetRaw()->RecoveryTime;
    }
    
    auto GetCategoryRecoveryTime() const noexcept {
        return GetRaw()->CategoryRecoveryTime;
    }
    
    auto GetInterruptFlags() const noexcept {
        return GetRaw()->InterruptFlags;
    }
    
    auto GetAuraInterruptFlags() const noexcept {
        return GetRaw()->AuraInterruptFlags;
    }
    
    auto GetChannelInterruptFlags() const noexcept {
        return GetRaw()->ChannelInterruptFlags;
    }
    
    auto GetProcFlags() const noexcept {
        return GetRaw()->procFlags;
    }
    
    auto GetProcChance() const noexcept {
        return GetRaw()->procChance;
    }
    
    auto GetProcCharges() const noexcept {
        return GetRaw()->procCharges;
    }
    
    auto GetMaxLevel() const noexcept {
        return GetRaw()->maxLevel;
    }
    
    auto GetBaseLevel() const noexcept {
        return GetRaw()->baseLevel;
    }
    
    auto GetSpellLevel() const noexcept {
        return GetRaw()->spellLevel;
    }
    
    auto GetDurationIndex() const noexcept {
        return GetRaw()->DurationIndex;
    }
    
    auto GetPowerType() const noexcept {
        return GetRaw()->powerType;
    }
    
    auto GetManaCost() const noexcept {
        return GetRaw()->manaCost;
    }
    
    auto GetManaCostPerlevel() const noexcept {
        return GetRaw()->manaCostPerlevel;
    }
    
    auto GetManaPerSecond() const noexcept {
        return GetRaw()->manaPerSecond;
    }
    
    auto GetManaPerSecondPerLevel() const noexcept {
        return GetRaw()->manaPerSecondPerLevel;
    }
    
    auto GetRangeIndex() const noexcept {
        return GetRaw()->rangeIndex;
    }
    
    auto GetSpeed() const noexcept {
        return GetRaw()->speed;
    }
    
    auto GetModalNextSpell() const noexcept {
        return GetRaw()->modalNextSpell;
    }
    
    auto GetStackAmount() const noexcept {
        return GetRaw()->StackAmount;
    }
    
    // uint32    Totem[MAX_SPELL_TOTEMS];                  // 40-41
    auto GetTotems() const noexcept {
        return GetRaw()->Totem;
    }
    // int32     Reagent[MAX_SPELL_REAGENTS];              // 42-49
    auto GetReagents() const noexcept {
        return GetRaw()->Reagent;
    }
    // uint32    ReagentCount[MAX_SPELL_REAGENTS];         // 50-57
    auto GetReagentsCounts() const noexcept {
        return GetRaw()->ReagentCount;
    }

    auto GetEquippedItemClass() const noexcept {
        return GetRaw()->EquippedItemClass;
    }

    auto GetEquippedItemSubClassMask() const noexcept {
        return GetRaw()->EquippedItemSubClassMask;
    }

    auto GetEquippedItemInventoryTypeMask() const noexcept {
        return GetRaw()->EquippedItemInventoryTypeMask;
    }

    // uint32    Effect[MAX_EFFECT_INDEX];                 // 61-63
    auto GetEffects() const noexcept {
        return GetRaw()->Effect;
    }
    // int32     EffectDieSides[MAX_EFFECT_INDEX];         // 64-66
    auto GetEffectsDieSides() const noexcept {
        return GetRaw()->EffectDieSides;
    }
    // uint32    EffectBaseDice[MAX_EFFECT_INDEX];         // 67-69
    auto GetEffectsBaseDice() const noexcept {
        return GetRaw()->EffectBaseDice;
    }
    // float     EffectDicePerLevel[MAX_EFFECT_INDEX];     // 70-72
    auto GetEffectsDicePerLevel() const noexcept {
        return GetRaw()->EffectDicePerLevel;
    }
    // float     EffectRealPointsPerLevel[MAX_EFFECT_INDEX];   // 73-75
    auto GetEffectsRealPointsPerLevel() const noexcept {
        return GetRaw()->EffectRealPointsPerLevel;
    }
    // int32     EffectBasePoints[MAX_EFFECT_INDEX];       // 76-78 (don't must be used in spell/auras explicitly, must be used cached Spell::m_currentBasePoints)
    auto GetEffectsBasePoints() const noexcept {
        return GetRaw()->EffectBasePoints;
    }
    // uint32    EffectMechanic[MAX_EFFECT_INDEX];         // 79-81
    auto GetEffectsMechanic() const noexcept {
        return GetRaw()->EffectMechanic;
    }
    // uint32    EffectImplicitTargetA[MAX_EFFECT_INDEX];  // 82-84
    auto GetEffectsImplicitTargetA() const noexcept {
        return GetRaw()->EffectImplicitTargetA;
    }
    // uint32    EffectImplicitTargetB[MAX_EFFECT_INDEX];  // 85-87
    auto GetEffectsImplicitTargetB() const noexcept {
        return GetRaw()->EffectImplicitTargetB;
    }
    // uint32    EffectRadiusIndex[MAX_EFFECT_INDEX];      // 88-90 - spellradius.dbc
    auto GetEffectsRadiusIndex() const noexcept {
        return GetRaw()->EffectRadiusIndex;
    }
    // uint32    EffectApplyAuraName[MAX_EFFECT_INDEX];    // 91-93
    auto GetEffectsApplyAuraName() const noexcept {
        return GetRaw()->EffectApplyAuraName;
    }
    // uint32    EffectAmplitude[MAX_EFFECT_INDEX];        // 94-96
    auto GetEffectsAmplitude() const noexcept {
        return GetRaw()->EffectAmplitude;
    }
    // float     EffectMultipleValue[MAX_EFFECT_INDEX];    // 97-99
    auto GetEffectsMultipleValue() const noexcept {
        return GetRaw()->EffectMultipleValue;
    }
    // uint32    EffectChainTarget[MAX_EFFECT_INDEX];      // 100-102
    auto GetEffectsChainTarget() const noexcept {
        return GetRaw()->EffectChainTarget;
    }
    // uint32    EffectItemType[MAX_EFFECT_INDEX];         // 103-105
    auto GetEffectsItemType() const noexcept {
        return GetRaw()->EffectItemType;
    }
    // int32     EffectMiscValue[MAX_EFFECT_INDEX];        // 106-108
    auto GetEffectsMiscValue() const noexcept {
        return GetRaw()->EffectMiscValue;
    }
    // uint32    EffectTriggerSpell[MAX_EFFECT_INDEX];     // 109-111
    auto GetEffectsTriggerSpell() const noexcept {
        return GetRaw()->EffectTriggerSpell;
    }
    // float     EffectPointsPerComboPoint[MAX_EFFECT_INDEX];  // 112-114
    auto GetEffectsPointsPerComboPoint() const noexcept {
        return GetRaw()->EffectPointsPerComboPoint;
    }

    auto GetSpellVisual() const noexcept {
        return GetRaw()->SpellVisual;
    }

    auto GetSpellIconID() const noexcept {
        return GetRaw()->SpellIconID;
    }

    auto GetActiveIconID() const noexcept {
        return GetRaw()->activeIconID;
    }

    auto GetSpellPriority() const noexcept {
        return GetRaw()->spellPriority;
    }

    constexpr static auto GetSpellNamesSize() noexcept {
        return std::extent_v<decltype(std::declval<BaseEntryView::DBCStruct>().SpellName)>;
    }

    auto GetDefaultSpellName() const noexcept {
        return GetRaw()->SpellName[0u];
    }

    auto GetSpellName(size_t idx) const noexcept {
        if (idx < GetSpellNamesSize()) {
            return GetRaw()->SpellName[idx];
        }
        return GetDefaultSpellName();
    }
    
    constexpr static auto GetRanksSize() noexcept {
        return std::extent_v<decltype(std::declval<BaseEntryView::DBCStruct>().Rank)>;
    }

    auto GetRank(size_t idx) const noexcept {
        assert(idx < GetSpellNamesSize());
        return GetRaw()->Rank[idx];
    }

    auto GetManaCostPercentage() const noexcept {
        return GetRaw()->ManaCostPercentage;
    }

    auto GetStartRecoveryCategory() const noexcept {
        return GetRaw()->StartRecoveryCategory;
    }

    auto GetStartRecoveryTime() const noexcept {
        return GetRaw()->StartRecoveryTime;
    }

    auto GetMaxTargetLevel() const noexcept {
        return GetRaw()->MaxTargetLevel;
    }

    auto GetSpellFamilyName() const noexcept {
        return GetRaw()->SpellFamilyName;
    }

    auto GetSpellFamilyFlags() const noexcept {
        return GetRaw()->SpellFamilyFlags;
    }

    auto GetMaxAffectedTargets() const noexcept {
        return GetRaw()->MaxAffectedTargets;
    }

    auto GetDamageClass() const noexcept {
        return GetRaw()->DmgClass;
    }

    auto GetPreventionType() const noexcept {
        return GetRaw()->PreventionType;
    }

    auto GetStanceBarOrder() const noexcept {
        return GetRaw()->StanceBarOrder;
    }

    constexpr static auto GetDamageMultipliersSize() noexcept {
        return std::extent_v<decltype(std::declval<BaseEntryView::DBCStruct>().DmgMultiplier)>;
    }

    auto GetDamageMultipliers() const noexcept {
        return GetRaw()->DmgMultiplier;
    }

    auto GetMinFactionId() const noexcept {
        return GetRaw()->MinFactionId;
    }

    auto GetMinReputation() const noexcept {
        return GetRaw()->MinReputation;
    }

    auto GetRequiredAuraVision() const noexcept {
        return GetRaw()->RequiredAuraVision;
    }

    constexpr static auto GetEffectsBonusCoefficientSize() noexcept {
        return std::extent_v<decltype(std::declval<BaseEntryView::DBCStruct>().effectBonusCoefficient)>;
    }

    auto GetEffectsBonusCoefficient() const noexcept {
        return GetRaw()->effectBonusCoefficient;
    }

    constexpr static auto GetEffectsBonusCoefficientFromAPSize() noexcept {
        return std::extent_v<decltype(std::declval<BaseEntryView::DBCStruct>().effectBonusCoefficientFromAP)>;
    }

    auto GetEffectsBonusCoefficientFromAP() const noexcept {
        return GetRaw()->effectBonusCoefficientFromAP;
    }

    auto GetIsServerSide() const noexcept {
        return GetRaw()->IsServerSide;
    }

    auto GetAttributesServerside() const noexcept {
        return GetRaw()->AttributesServerside;
    }

    // helpers
    auto CalculateSimpleValue(SpellEffectIndex idx) const { return GetRaw()->CalculateSimpleValue(idx); }
    auto IsFitToFamilyMask(uint64 familyFlags) const { return GetRaw()->IsFitToFamilyMask(familyFlags); }
    auto IsFitToFamily(SpellFamily family, uint64 familyFlags) const { return GetRaw()->IsFitToFamily(family, familyFlags); }
    auto IsFitToFamilyMask(ClassFamilyMask const& mask) const { return GetRaw()->IsFitToFamilyMask(mask); }
    auto IsFitToFamily(SpellFamily family, ClassFamilyMask const& mask) const { return GetRaw()->IsFitToFamily(family, mask); }

    template<typename SpellAttributesType>
    bool HasAttribute(SpellAttributesType attribute) const { return GetRaw()->HasAttribute(attribute); }
    auto GetAllEffectsMechanicMask() const { return GetRaw()->GetAllEffectsMechanicMask(); }
    auto GetSchoolMask() const { return GetRaw()->GetSchoolMask(); }
};

template<> auto SpellView::GetAttributesExtensions<1>() const noexcept;

template<> auto SpellView::GetAttributesExtensions<2>() const noexcept;

template<> auto SpellView::GetAttributesExtensions<3>() const noexcept;

template<> auto SpellView::GetAttributesExtensions<4>() const noexcept;

class TaxiNodeView: public BaseEntryView<TaxiNodesEntry, TaxiNodeView>
{
public:
    using BaseEntryView<TaxiNodesEntry, TaxiNodeView>::BaseEntryView;

    auto GetID() const noexcept {
        return GetRaw()->ID;
    }

    auto GetMapId() const noexcept {
        return GetRaw()->map_id;
    }

    std::tuple<float, float, float> GetCoordinates() const noexcept {
        return std::make_tuple(GetRaw()->x, GetRaw()->y, GetRaw()->z);
    }

    constexpr static auto GetNamesSize() noexcept {
        return std::extent_v<decltype(std::declval<BaseEntryView::DBCStruct>().name)>;
    }

    auto GetDefaultName() const noexcept {
        return GetRaw()->name[0u];
    }

    auto GetName(size_t idx) const noexcept {
        if (idx < GetNamesSize()) {
            return GetRaw()->name[idx];
        }
        return GetDefaultName();
    }

    auto GetMountCreatureID() const noexcept {
        return GetRaw()->MountCreatureID;
    }
};

class WMOAreaView: public BaseEntryView<WMOAreaTableEntry, WMOAreaView>
{
public:
    using BaseEntryView<WMOAreaTableEntry, WMOAreaView>::BaseEntryView;

    auto GetID() const noexcept {
        return GetRaw()->Id;
    }

    auto GetRootID() const noexcept {
        return GetRaw()->rootId;
    }

    auto GetADTID() const noexcept {
        return GetRaw()->adtId;
    }

    auto GetGroupID() const noexcept {
        return GetRaw()->groupId;
    }

    auto GetFlags() const noexcept {
        return GetRaw()->Flags;
    }

    auto GetAreaID() const noexcept {
        return GetRaw()->areaId;
    }

    constexpr static auto GetNamesSize() noexcept {
        return std::extent_v<decltype(std::declval<BaseEntryView::DBCStruct>().Name)>;
    }

    auto GetDefaultName() const noexcept {
        return GetRaw()->Name[0u];
    }

    auto GetName(size_t idx) const noexcept {
        if (idx < GetNamesSize()) {
            return GetRaw()->Name[idx];
        }
        return GetDefaultName();
    }
};

} // entry::view
