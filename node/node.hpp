#ifndef NODE_HPP
#define NODE_HPP

#include <memory>
#include <vector>
#include <iostream>


namespace tictactoe {

class Node;
using noderef = std::shared_ptr<Node>;

class Node: public std::enable_shared_from_this<Node> {
    public:

    inline Node(const size_t movement) {
        _movement = movement;
        _times_visited = 0;
        _victories = 0;
        _parent = nullptr;
    }

    inline Node(const size_t movement, const noderef parent) {
        _movement = movement;
        _times_visited = 0;
        _victories = 0;
        _parent = parent;
    }

    static inline noderef create(const size_t movement) {
        return std::make_shared<Node>(movement);
    }

    static inline noderef create(const size_t movement, const noderef parent) {
        return std::make_shared<Node>(movement, parent);
    }

    inline size_t victories()  const {
        return _victories;
    }

    inline size_t visitings() const {
        return _times_visited;
    }

    inline noderef parent() const {
        return _parent;
    }

    // noderef select();
    // void expand(noderef node, Board &board);
    // void rollout(noderef node, Board &board);

    inline friend std::ostream& operator<< (std::ostream& os, const Node& node) {
        os << "node(movement = " << node._movement
           << " visits = " << node._times_visited
           << " victories = " << node._victories << ")";
        return os;
    }


    private:
    size_t _movement;
    size_t _times_visited;
    size_t _victories;
    noderef _parent;
    std::vector<noderef> _possibilities;
};

}
#endif
