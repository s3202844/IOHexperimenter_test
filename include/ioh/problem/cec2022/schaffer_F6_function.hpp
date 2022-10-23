#pragma once

#include "cec2022_problem.hpp"
// #include "json.hpp"

namespace ioh::problem::cec2022
{
    class SchafferF6Function final : public CEC2022Problem<SchafferF6Function>
    {
    protected:
        double schaffer(const double x, const double y)
        {
            double z = pow(x, 2) + pow(y, 2);
            double num = pow(sin(pow(z, 0.5)), 2) - 0.5;
            double den = pow(1 + 0.001 * z, 2);
            return 0.5 + num / den;
        }
        //! Evaluation method
        double evaluate(const std::vector<double> &x) override
        {
            std::vector<double> new_x;
            new_x = shift_func(x);
            // for (size_t i = 0; i < new_x.size(); i++)
            // {
            //     double xi = new_x.at(i);
            //     new_x.at(i) = xi * 0.5 / 100;
            // }
            // new_x = rotate_func(new_x);
            auto result = 0.0;
            for (size_t i = 0; i < new_x.size(); i++)
            {
                result += schaffer(new_x.at(i), new_x.at((i + 1) % new_x.size()));
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
        SchafferF6Function(const int instance, const int n_variables) :
            CEC2022Problem(1, instance, n_variables, "SchafferF7Function")
        {
        }
    };
} // namespace ioh::problem::cec2022