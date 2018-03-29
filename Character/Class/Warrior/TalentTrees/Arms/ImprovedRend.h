#ifndef IMPROVEDREND_H
#define IMPROVEDREND_H

#include "Talent.h"

class ImprovedRend: public Talent {
    Q_OBJECT
public:
    ImprovedRend(Character *pchar);
    virtual ~ImprovedRend();

    virtual void apply_rank_effect() override;
    virtual void remove_rank_effect() override;

private:
};

#endif // IMPROVEDREND_H