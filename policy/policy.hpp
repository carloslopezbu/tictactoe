#ifndef POLICY_HPP
#define POLICY_HPP
#include <cmath>
#include <limits>
#include <memory>
#include <iostream>
#include <string>
#include "../node/node.hpp"

namespace tictactoe {

    namespace policy {

    class Policy;
    using policyref = std::shared_ptr<Policy>;

    class Policy {
      public:
      virtual float apply(noderef node) = 0;
      virtual const std::string describe() const = 0;
    };

    class Ucb: public Policy {
        public:
        inline Ucb(const float &C) {
            this->_C = C;
        }

        inline static policyref create(const float &C) {
            return std::make_shared<Ucb>(C);
        }

        float apply(noderef node) {
            const float num_wins = ( float ) node->victories();
            const float visits = ( float ) node->visitings();
            const noderef p = node->parent();

            if (!p)
                return std::numeric_limits<float>::infinity();

            const float parent_visits = ( float ) p->visitings();


            if (visits == 0 || parent_visits == 0)
                return std::numeric_limits<float>::infinity() ;

            return num_wins / visits + C() * std::sqrt(std::log(parent_visits) / visits);
        }

        const float C() const {
            return _C;
        }

        const std::string describe() const {
            return "Ucb(C = " + std::to_string(_C) + ")";
        }

        private:
        float _C;
    };

    inline std::ostream& operator<<(std::ostream& os, const tictactoe::policy::Policy& p) {
        return os << p.describe();
    }
    }
}


#endif
