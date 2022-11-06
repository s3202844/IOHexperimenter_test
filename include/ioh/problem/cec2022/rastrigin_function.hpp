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
            // int nx = x.size();
            std::vector<double> new_x;
            new_x = shift_func(x);
            for (int i = 0; i < nx; i++)
            {
                double xi = new_x.at(i);
                new_x.at(i) = xi * 5.12 / 100.0;
            }
            new_x = rotate_func(new_x);
            auto result = 0.0;
            for (int i = 0; i < nx; i++)
            {
                result += pow(new_x.at(i), 2) - 10.0 * cos(2.0 * M_PI * new_x.at(i)) + 10.0;
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
            CEC2022Problem(1, instance, n_variables, "RastriginFunction")
        {
        }
    };
} // namespace ioh::problem::cec2022