#pragma once

#include "cec_basic_funcs.hpp"
#include "cec_utils.hpp"
#include "ioh/problem/problem.hpp"


namespace ioh::problem
{


    //! CEC2022 base class
    class CEC2022 : public Real
    {
    protected:
        int fn_;
        int nx_;
        std::vector<double> Os_;
        std::vector<double> Mr_;

    public:
        /**
         * @brief Construct a new CEC2022 object
         *
         * @param problem_id The id of the problem
         * @param instance The instance of the problem
         * @param n_variables the dimension of the problem
         * @param name the name of the problem
         */
        CEC2022(const int problem_id, const int instance, const int n_variables,
                const std::string &name) :
            Real(MetaData(problem_id, instance, name, n_variables),
                 Bounds<double>(n_variables, -100, 100))
        {
            fn_ = problem_id;
            nx_ = n_variables;
            loadCecData();
            // optimum_=0;
            log_info_.optimum = optimum_;
        }

        void loadCecData()
        {
            std::string dataPath =
                "/usr/local/include/ioh/problem/cec/cec_data";
            cec::loadOShiftData(&Os_, dataPath, nx_, fn_, 2022);
            cec::loadMatrixData(&Mr_, dataPath, nx_, fn_, 2022);
        }
    };

    /**
     * @brief CRTP class for BBOB problems. Inherit from this class when
     * defining new BBOB problems
     *
     * @tparam ProblemType The New BBOB problem class
     */
    template <typename ProblemType>
    class CEC2022Problem : public CEC2022,
                           AutomaticProblemRegistration<ProblemType, CEC2022>,
                           AutomaticProblemRegistration<ProblemType, Real>
    {

    public:
        /**
         * @brief Construct a new BBOProblem object
         *
         * @param problem_id The id of the problem
         * @param instance The instance of the problem
         * @param n_variables the dimension of the problem
         * @param name the name of the problem
         */
        CEC2022Problem(const int problem_id, const int instance,
                       const int n_variables, const std::string &name) :
            CEC2022(problem_id, instance, n_variables, name)
        {
        }
    };
} // namespace ioh::problem