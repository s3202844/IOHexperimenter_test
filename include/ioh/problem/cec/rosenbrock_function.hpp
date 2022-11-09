#pragma once

#include "cec2022_problem.hpp"
// #include "json.hpp"

namespace ioh::problem::cec
{
    class RosenbrockFunction final : public CEC2022Problem<RosenbrockFunction>
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
                new_x.at(i) = xi * 2.048 / 100;
            }
            new_x = rotate_func(new_x);
            for (int i = 0; i < nx; i++)
            {
                new_x.at(i) += 1;
            }
            auto result = 0.0;
            for (int i = 0; i < nx - 1; i++)
            {
                double item = 0.0;
                item = item + 100 * pow((pow(new_x.at(i), 2) - new_x.at(i + 1)), 2);
                item = item + pow((new_x.at(i) - 1), 2);
                result = result + item;
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
        RosenbrockFunction(const int instance, const int n_variables) :
            CEC2022Problem(1, instance, n_variables, "RosenbrockFunction")
        {
        }
    };
} // namespace ioh::problem::cec2022