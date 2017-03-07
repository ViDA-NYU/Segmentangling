#ifndef SIMFUNCTION_HPP
#define SIMFUNCTION_HPP

#include <QVector>
#include <stdint.h>

struct Branch {
    uint32_t from;
    uint32_t to;
    QVector<uint32_t> arcs;

    uint32_t parent;
    QVector<uint32_t> children;
};

class SimFunction
{
public:
    virtual void init(std::vector<float>& fn, std::vector<Branch>& br) = 0;
    virtual void update(const std::vector<Branch>& br, uint32_t brNo) = 0;
    virtual void branchRemoved(std::vector<Branch>& br, uint32_t brNo, std::vector<bool>& invalid) = 0;
    virtual float getBranchWeight(uint32_t brNo) = 0;
};

#endif // SIMFUNCTION_HPP