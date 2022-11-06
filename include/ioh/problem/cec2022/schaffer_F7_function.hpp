#pragma once

#include "cec2022_problem.hpp"
// #include "json.hpp"

namespace ioh::problem::cec2022
{
    class SchafferF7Function final : public CEC2022Problem<SchafferF7Function>
    {
    protected:
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
            new_x = rotate_func(new_x);
            auto result = 0.0;
            for (size_t i = 0; i < new_x.size() - 1; i++)
            {
                double xi = new_x.at(i);
                double xi1 = new_x.at(i + 1);
                double si = pow(pow(xi, 2) + pow(xi1, 2), 0.5);
                double tmp = sin(50.0 * pow(si, 0.2));
                result += pow(si, 0.5) + pow(si, 0.5) * tmp * tmp;
            }
            result = result * result / (nx - 1) / (nx - 1);
            return result;
        }

    public:
        /**
         * @brief
         *
         * @param instance instance id
         * @param n_variables the dimension of the problem
         */
        SchafferF7Function(const int instance, const int n_variables) :
            CEC2022Problem(1, instance, n_variables, "SchafferF7Function")
        {
        }
    };
} // namespace ioh::problem::cec2022