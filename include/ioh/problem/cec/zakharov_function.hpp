#pragma once

#include "cec2022_problem.hpp"
// #include "json.hpp"

namespace ioh::problem::cec
{
    class ZakharovFunction final : public CEC2022Problem<ZakharovFunction>
    {
    protected:
        //! Evaluation method
        double evaluate(const std::vector<double> &x) override
        {
            // int nx = x.size();
            std::vector<double> test_x(x);
            // std::vector<double> new_x;
            // new_x = shift_func(x);
            // new_x = rotate_func(new_x);
            sr_func(test_x, tvec_, rvec_, 1, 1, 1, nx);
            auto result = 0.0;
            std::vector<double> terms = {0, 0};
            for (int i = 0; i < nx; i++)
            {
                terms.at(0) += pow(test_x.at(i), 2);
                terms.at(1) += 0.5 * (i + 1) * test_x.at(i);
            }
            result = terms.at(0) + pow(terms.at(1), 2) + pow(terms.at(1), 4);
            return result;
        }

    public:
        /**
         * @brief
         *
         * @param instance instance id
         * @param n_variables the dimension of the problem
         */
        ZakharovFunction(const int instance, const int n_variables) :
            CEC2022Problem(1, instance, n_variables, "ZakharovFunction")
        {
        }
    };
} // namespace ioh::problem::cec2022