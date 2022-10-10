#pragma once

#include "cec2022_problem.hpp"
// #include "json.hpp"

namespace ioh::problem::cec2022
{
    class RastriginFunction final : public CEC2022Problem<RastriginFunction>
    {
    protected:
        //! Evaluation method
        double evaluate(const std::vector<double> &x) override
        {
            std::vector<double> tempx;
            tempx = shift_func(x);
            for (size_t i = 0; i < tempx.size(); i++)
            {
                double xi = tempx.at(i);
                tempx.at(i) = xi * 5.12 / 100;
            }
            tempx = rotate_func(tempx);
            auto result = 0.0;
            for (size_t i = 0; i < tempx.size(); i++)
            {
                result += pow(tempx.at(i), 2) - 10 * cos(2 * M_PI * tempx.at(i)) + 10;
            }
            return result;
        }

    public:
        /**
         * @brief
         *
         * @param instance instance id
         * @param n_variables the dimension of the problem
         */
        RastriginFunction(const int instance, const int n_variables) :
            CEC2022Problem(1, instance, n_variables, "SchafferF7Function")
        {
        }
    };
} // namespace ioh::problem::cec2022