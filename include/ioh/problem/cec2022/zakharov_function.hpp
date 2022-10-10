#pragma once

#include "cec2022_problem.hpp"
// #include "json.hpp"

namespace ioh::problem::cec2022
{
    class ZakharovFunction final : public CEC2022Problem<ZakharovFunction>
    {
    protected:
        //! Evaluation method
        double evaluate(const std::vector<double> &x) override
        {
            auto result = 0.0;
            std::vector<double> items = {0, 0};
            for (size_t i = 0; i < x.size(); i++)
            {
                items.at(0) += pow(x.at(i), 2);
                items.at(1) += x.at(i) * 0.5;
            }
            result = items.at(0) + pow(items.at(1), 2) + pow(items.at(1), 4);
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