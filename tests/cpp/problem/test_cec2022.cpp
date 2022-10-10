#include "../utils.hpp"

#include "ioh/problem/cec2022.hpp"

TEST_F(BaseTest, ZakharovFunction)
{
    // const auto &problem_factory = ioh::problem::ProblemRegistry<ioh::problem::CEC2022>::instance();

    auto problem = ioh::problem::cec2022::ZakharovFunction(1, 2);
    std::cout << problem.optimum() << std::endl;
    std::vector<double> x1 = {0, 0};
    std::cout << problem(x1) << std::endl;
    std::vector<double> x2 = {1, 1};
    std::cout << problem(x2) << std::endl;
}

TEST_F(BaseTest, SchafferF6Function)
{
    // const auto &problem_factory = ioh::problem::ProblemRegistry<ioh::problem::CEC2022>::instance();

    std::vector<double> tvec = {7.9089392944746379e+01, -2.4572777647791789e+01};
    std::vector<double> rvec = {-8.1259572623023857e-01, 5.8282774960733563e-01, -5.8282774960733574e-01,
                                -8.1259572623023846e-01};
    auto problem = ioh::problem::cec2022::SchafferF6Function(1, 2);
    problem.tvec_ = tvec;
    problem.rvec_ = rvec;
    for (double x1 = 0.0; x1 < 100.0; x1 += 0.1)
    {
        for (double x2 = 0.0; x2 < 100.0; x2 += 0.1)
        {
            std::vector<double> x = {x1, x2};
            // std::cout << problem(x) << std::endl;
        }
    }
}

TEST_F(BaseTest, RastriginFunction)
{
    // const auto &problem_factory = ioh::problem::ProblemRegistry<ioh::problem::CEC2022>::instance();
    std::ofstream file;
    file.open("../F4.txt", std::ios::out);
    if (!file.is_open())
    {
        std::cout << "open failed" << std::endl;
    }
    std::vector<double> tvec = {3.2164219372050951e+01, -5.5965013939870992e+01};
    std::vector<double> rvec = {7.7917055529751778e-01, -6.2681197001761013e-01, 6.2681197001761058e-01,
                                7.7917055529751800e-01};
    auto problem = ioh::problem::cec2022::RastriginFunction(1, 2);
    problem.tvec_ = tvec;
    problem.rvec_ = rvec;
    for (double x1 = -100.0; x1 <= 100.0; x1 += 0.5)
    {
        for (double x2 = -100.0; x2 <= 100.0; x2 += 0.5)
        {
            std::vector<double> x = {x1, x2};
            file << std::to_string(x1) << " " << std::to_string(x2) << " " << std::to_string(problem(x)) << std::endl;
        }
    }
    file.close();
}
