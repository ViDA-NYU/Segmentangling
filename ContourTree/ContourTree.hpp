#ifndef CONTOURTREE_HPP
#define CONTOURTREE_HPP

#include <QString>
#include <vector>

namespace contourtree {

class MergeTree;

class ContourTree
{
public:
    struct Node {
        int64_t v;
        std::vector<int64_t> next;
        std::vector<int64_t> prev;
    };

public:
    ContourTree();

    void setup(const MergeTree * tree);
    void computeCT();
    void output(QString fileName);

private:
    void remove(int64_t xi, std::vector<Node>& nodeArray);
    void removeAndAdd(std::vector<int64_t> &arr, int64_t rem, int64_t add);
    void remove(std::vector<int64_t> &arr, int64_t xi);
    void addArc(int64_t from, int64_t to);

public:
    const MergeTree * tree;
    std::vector<Node> nodesJoin;
    std::vector<Node> nodesSplit;
    int64_t nv;
    int64_t noarcs;
};

}

#endif // CONTOURTREE_HPP
