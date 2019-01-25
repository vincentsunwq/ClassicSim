
#include "ImprovedCleave.h"
#include "Character.h"

ImprovedCleave::ImprovedCleave(Character *pchar, TalentTree* tree) :
    Talent(pchar, tree, "Improved Cleave", "3LL", "Assets/ability/Ability_warrior_cleave.png", 3)
{
    QString base_str = "Increases the bonus damage done by your Cleave ability by %1%.";
    initialize_rank_descriptions(rank_descriptions, base_str, max_points, QVector<QPair<int, int>>{{40, 40}});
}

ImprovedCleave::~ImprovedCleave() = default;

void ImprovedCleave::apply_rank_effect() {
    // TODO: Decide how rank effects work for this talent.
}

void ImprovedCleave::remove_rank_effect() {
    // TODO: Decide how rank effects work for this talent.
}
