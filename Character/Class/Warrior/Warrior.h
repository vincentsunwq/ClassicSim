#ifndef WARRIOR_H
#define WARRIOR_H

#include "Character.h"

class CombatRoll;
class Talents;
class Bloodthirst;
class MainhandAttack;
class OffhandAttack;
class Flurry;
class DeepWounds;
class HeroicStrike;
class HeroicStrikeBuff;
class Execute;
class Overpower;

class Warrior: public Character {
    Q_OBJECT
public:
    Warrior(Race* race, Engine* engine, Equipment* _eq, CombatRoll* _roll, QObject *parent = 0);
    virtual ~Warrior();

    QString get_name() const override;
    QString get_class_color() const override;
    int get_strength_modifier() const override;
    int get_agility_modifier() const override;
    int get_stamina_modifier() const override;
    int get_intellect_modifier() const override;
    int get_spirit_modifier() const override;
    void rotation() override;
    void mh_auto_attack(const int) override;
    void oh_auto_attack(const int) override;
    float global_cooldown() const override;
    int get_curr_rage() const;
    void gain_rage(const int);
    void lose_rage(const int);
    int rage_gained_from_dd(const int) const;

    bool bt_available(void) const;

    Bloodthirst* get_bloodthirst() const;
    Flurry* get_flurry() const;
    DeepWounds* get_deep_wounds() const;
    HeroicStrike* get_heroic_strike() const;
    HeroicStrikeBuff* get_hs_buff() const;
    Execute* get_execute() const;
    Overpower* get_overpower() const;
    OffhandAttack* get_offhand_attack() const;

    void melee_critical_effect();

    int get_ap_per_strength() const override;
    int get_ap_per_agi() const override;

    void increase_attack_speed(int) override;
    void decrease_attack_speed(int) override;

    void reset_resource() override;

protected:
private:
    int rage;
    Bloodthirst* bt;
    MainhandAttack* mh_attack;
    OffhandAttack* oh_attack;
    Flurry* flurry;
    DeepWounds* deep_wounds;
    HeroicStrike* heroic_strike;
    HeroicStrikeBuff* heroic_strike_buff;
    Execute* execute;
    Overpower* overpower;

    void add_next_mh_attack(void) override;
    void add_next_oh_attack(void) override;

    void initialize_talents() override;
};

#endif // WARRIOR_H
