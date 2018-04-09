
#include "HeroicStrike.h"
#include "Warrior.h"
#include "Flurry.h"
#include "DeepWounds.h"
#include "HeroicStrikeBuff.h"

HeroicStrike::HeroicStrike(Engine* engine, Character* pchar, CombatRoll* roll) :
    Spell("Heroic Strike", engine, pchar, roll, 0, 15)
{
    this->pchar = dynamic_cast<Warrior*>(pchar);

    spell_ranks = {11, 21, 32, 44, 58, 80, 111, 138, 157};
    // TODO: Remove hardcoded assumption of rank 9 Heroic Strike.
    rank_spell = 8;
    additional_dmg = spell_ranks[rank_spell];

    talent_ranks = {15, 14, 13, 12};
}

int HeroicStrike::spell_effect(const int) {
    pchar->get_hs_buff()->use_charge();

    AttackResult* result = roll->get_melee_ability_result(pchar->get_mh_wpn_skill());

    if (result->is_miss()) {
        add_fail_stats("Miss");
    }
    // TODO: Apply Overpower
    if (result->is_dodge()) {
        add_fail_stats("Dodge");
    }
    if (result->is_parry()) {
        add_fail_stats("Parry");
    }

    float damage_dealt = pchar->get_random_mh_dmg() + additional_dmg;

    if (result->is_critical()) {
        damage_dealt *= pchar->get_ability_crit_dmg_mod();
        pchar->melee_critical_effect();
        add_success_stats("Critical", round(damage_dealt));
    }
    else if (result->is_hit())
        add_success_stats("Hit", round(damage_dealt));

    return resource_cost;
}

void HeroicStrike::increase_effect_via_talent() {
    ++rank_talent;
    // TODO: Assert max rank?
    resource_cost = talent_ranks[rank_talent];
}

void HeroicStrike::decrease_effect_via_talent() {
    --rank_talent;
    assert(rank_talent >= 0);
    resource_cost = talent_ranks[rank_talent];
}
