#ifndef HEROICSTRIKE_H
#define HEROICSTRIKE_H

#include "Spell.h"
#include "TalentRequirer.h"

class NoEffectBuff;
class Warrior;

class HeroicStrike: public Spell, public TalentRequirer {
public:
    HeroicStrike(Character* pchar);
    ~HeroicStrike() override;

    bool is_queued() const;
    void cancel();
    void calculate_damage();

protected:
private:
    Warrior* warr;
    NoEffectBuff* hs_buff;
    QVector<int> spell_ranks;
    QVector<int> talent_ranks;
    int additional_dmg;

    void spell_effect() override;

    void increase_talent_rank_effect(const QString& talent_name, const int curr) override;
    void decrease_talent_rank_effect(const QString& talent_name, const int curr) override;
};

#endif // HEROICSTRIKE_H
