#pragma once

#include "ioh/common/factory.hpp"
#include "ioh/problem/problem.hpp"
#include "ioh/problem/transformation.hpp"


namespace ioh::problem
{


    //! CEC2022 base class
    class CEC2022 : public Real
    {

    public:
        /**
         * @brief Construct a new CEC2022 object
         *
         * @param problem_id The id of the problem
         * @param instance The instance of the problem
         * @param n_variables the dimension of the problem
         * @param name the name of the problem
         */
        CEC2022(const int problem_id, const int instance, const int n_variables, const std::string &name) :
            Real(MetaData(problem_id, instance, name, n_variables), Bounds<double>(n_variables, -100, 100))
        {
            // optimum_=0;
            log_info_.optimum = optimum_;
        }
    };

    /**
     * @brief CRTP class for BBOB problems. Inherit from this class when defining new BBOB problems
     *
     * @tparam ProblemType The New BBOB problem class
     */
    template <typename ProblemType>
    class CEC2022Problem : public CEC2022,
                           AutomaticProblemRegistration<ProblemType, CEC2022>,
                           AutomaticProblemRegistration<ProblemType, Real>
    {
    protected:
        int nx;

        std::vector<double> shift_func(const std::vector<double> &x)
        {
            std::vector<double> result;
            for (size_t i = 0; i < x.size(); i++)
            {
                result.push_back(x.at(i) - tvec_.at(i));
            }
            return result;
        }

        std::vector<double> rotate_func(const std::vector<double> &x)
        {
            std::vector<double> result;
            for (size_t i = 0; i < x.size(); i++)
            {
                double xrot = 0.0;
                for (size_t j = 0; j < x.size(); j++)
                {
                    xrot = xrot + x.at(j) * rvec_.at(i * (x.size()) + j);
                }
                result.push_back(xrot);
            }
            return result;
        }

    public:
        std::vector<double> tvec_;
        std::vector<double> rvec_;

        /**
         * @brief Construct a new BBOProblem object
         *
         * @param problem_id The id of the problem
         * @param instance The instance of the problem
         * @param n_variables the dimension of the problem
         * @param name the name of the problem
         */
        CEC2022Problem(const int problem_id, const int instance, const int n_variables, const std::string &name) :
            CEC2022(problem_id, instance, n_variables, name)
        {
            nx = n_variables;
        }
    };
} // namespace ioh::problem
