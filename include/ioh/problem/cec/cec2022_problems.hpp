#pragma once

#include "cec2022.hpp"


namespace ioh::problem::cec
{
    class cec2022_01 final : public CEC2022Problem<cec2022_01>
    {
    protected:
        double evaluate(const std::vector<double> &x) override
        {
            std::vector<double> sr_x(x);
            return cec::zakharov_func(sr_x, Os_, Mr_, true, true, nx_);
        }

    public:
        cec2022_01(const int instance, const int n_variables) :
            CEC2022Problem(1, instance, n_variables, "cec2022_01")
        {
        }
    };
} // namespace ioh::problem::cec
