#ifndef MCTS_HPP
#define MCTS_HPP

#include <cassert>
#include <cstddef>
#include <vector>

#include "../node/node.hpp"
#include "../policy/policy.hpp"
#include "../board/board.hpp"

namespace tictactoe {

class Mcts {
    public:
    inline Mcts() {
        _policy = nullptr;
    }

    inline void set_policy(policy::policyref policy) {
        _policy = policy;
    }

    inline friend std::ostream& operator<<(std::ostream& os, const Mcts& m) {

        assert(m._policy != nullptr && "A policy is needed");
        return os << "Mcts(policy = " << *m._policy << ")";
    }


    noderef select();
    void expand(noderef node, Board &board);
    void rollout(noderef node, Board &board);
    size_t operator()(Board &board);

    private:
    policy::policyref _policy;
    std::vector<noderef> _possibilities;
};

}

#endif
