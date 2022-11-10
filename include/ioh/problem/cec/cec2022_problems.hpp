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
            double f = cec::zakharov_func(sr_x, Os_, Mr_, true, true, nx_);
            return f + 300.0;
        }

    public:
        cec2022_01(const int instance, const int n_variables) :
            CEC2022Problem(1, instance, n_variables, "cec2022_01")
        {
        }
    };

    class cec2022_02 final : public CEC2022Problem<cec2022_02>
    {
    protected:
        double evaluate(const std::vector<double> &x) override
        {
            std::vector<double> sr_x(x);
            double f = cec::rosenbrock_func(sr_x, Os_, Mr_, true, true, nx_);
            return f + 400.0;
        }

    public:
        cec2022_02(const int instance, const int n_variables) :
            CEC2022Problem(2, instance, n_variables, "cec2022_02")
        {
        }
    };

    class cec2022_03 final : public CEC2022Problem<cec2022_03>
    {
    protected:
        double evaluate(const std::vector<double> &x) override
        {
            std::vector<double> sr_x(x);
            double f = cec::schaffer_F7_func(sr_x, Os_, Mr_, true, true, nx_);
            return f + 600.0;
        }

    public:
        cec2022_03(const int instance, const int n_variables) :
            CEC2022Problem(3, instance, n_variables, "cec2022_03")
        {
        }
    };

    class cec2022_04 final : public CEC2022Problem<cec2022_04>
    {
    protected:
        double evaluate(const std::vector<double> &x) override
        {
            std::vector<double> sr_x(x);
            double f =
                cec::step_rastrigin_func(sr_x, Os_, Mr_, true, true, nx_);
            return f + 800.0;
        }

    public:
        cec2022_04(const int instance, const int n_variables) :
            CEC2022Problem(4, instance, n_variables, "cec2022_04")
        {
        }
    };

    class cec2022_05 final : public CEC2022Problem<cec2022_05>
    {
    protected:
        double evaluate(const std::vector<double> &x) override
        {
            std::vector<double> sr_x(x);
            double f = cec::levy_func(sr_x, Os_, Mr_, true, true, nx_);
            return f + 900.0;
        }

    public:
        cec2022_05(const int instance, const int n_variables) :
            CEC2022Problem(5, instance, n_variables, "cec2022_05")
        {
        }
    };

} // namespace ioh::problem::cec
