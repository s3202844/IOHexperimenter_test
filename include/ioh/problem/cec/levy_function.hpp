#pragma once

#include "cec2022_problem.hpp"
// #include "json.hpp"

namespace ioh::problem::cec
{
    class LevyFunction final : public CEC2022Problem<LevyFunction>
    {
    protected:
        //! Evaluation method
        double evaluate(const std::vector<double> &x) override
        {
            std::vector<double> new_x;
            new_x = shift_func(x);
            new_x = rotate_func(new_x);

            double *w;
            w = (double *)malloc(sizeof(double) * nx);
            for (int i = 0; i < nx; i++)
            {
                w[i] = 1.0 + (new_x.at(i) - 1.0) / 4.0;
            }
            double term1 = pow((sin(M_PI * w[0])), 2);
            double term3 = pow((w[nx - 1] - 1), 2) * (1 + pow((sin(2 * M_PI * w[nx - 1])), 2));

            auto result = 0.0;
            for (int i = 0; i < nx - 1; i++)
            {
                double wi = w[i];
                double newv = pow((wi - 1), 2) * (1 + 10 * pow((sin(M_PI * wi + 1)), 2));
                result = result + newv;
            }
            result = term1 + result + term3;
            return result;
        }

    public:
        /**
         * @brief
         *
         * @param instance instance id
         * @param n_variables the dimension of the problem
         */
        LevyFunction(const int instance, const int n_variables) :
            CEC2022Problem(1, instance, n_variables, "LevyFunction")
        {
        }
    };
} // namespace ioh::problem::cec2022