#include "../utils.hpp"

#include "ioh/problem/cec2022.hpp"

TEST_F(BaseTest, ZakharovFunction)
{
    // const auto &problem_factory = ioh::problem::ProblemRegistry<ioh::problem::CEC2022>::instance();
    std::ofstream file;
    file.open("/home/ian/cec_core/results/exp_data/F1.txt", std::ios::out);
    if (!file.is_open())
    {
        std::cout << "open failed" << std::endl;
    }
    std::vector<double> tvec = {-5.5938326705218444e+01, 4.5430653935964642e+00};
    std::vector<double> rvec = {9.9965877537837600e-01, -2.6121500894966159e-02, -2.6121500894966111e-02,
                                -9.9965877537837589e-01};
    auto problem = ioh::problem::cec2022::ZakharovFunction(1, 2);
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

TEST_F(BaseTest, RosenbrockFunction)
{
    // const auto &problem_factory = ioh::problem::ProblemRegistry<ioh::problem::CEC2022>::instance();
    std::ofstream file;
    file.open("/home/ian/cec_core/results/exp_data/F2.txt", std::ios::out);
    if (!file.is_open())
    {
        std::cout << "open failed" << std::endl;
    }
    std::vector<double> tvec = {3.2510725014149543e+01, 7.7553128114693379e+00};
    std::vector<double> rvec = {8.2399197529768320e-01, 5.6660146897534813e-01, 5.6660146897534802e-01,
                                -8.2399197529768320e-01};
    auto problem = ioh::problem::cec2022::RosenbrockFunction(1, 2);
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

TEST_F(BaseTest, SchafferF7Function)
{
    // const auto &problem_factory = ioh::problem::ProblemRegistry<ioh::problem::CEC2022>::instance();
    std::ofstream file;
    file.open("/home/ian/cec_core/results/exp_data/F3.txt", std::ios::out);
    if (!file.is_open())
    {
        std::cout << "open failed" << std::endl;
    }
    std::vector<double> tvec = {7.9089392944746379e+01, -2.4572777647791789e+01};
    std::vector<double> rvec = {-8.1259572623023857e-01, 5.8282774960733563e-01, -5.8282774960733574e-01,
                                -8.1259572623023846e-01};
    auto problem = ioh::problem::cec2022::SchafferF7Function(1, 2);
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

TEST_F(BaseTest, RastriginFunction)
{
    // const auto &problem_factory = ioh::problem::ProblemRegistry<ioh::problem::CEC2022>::instance();
    std::ofstream file;
    file.open("/home/ian/cec_core/results/exp_data/F4.txt", std::ios::out);
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

TEST_F(BaseTest, LevyFunction)
{
    // const auto &problem_factory = ioh::problem::ProblemRegistry<ioh::problem::CEC2022>::instance();
    std::ofstream file;
    file.open("/home/ian/cec_core/results/exp_data/F5.txt", std::ios::out);
    if (!file.is_open())
    {
        std::cout << "open failed" << std::endl;
    }
    std::vector<double> tvec = {-2.4856254283737513e+01, 9.3425322367542663e-01};
    std::vector<double> rvec = {-9.6550846522825795e-01, 2.6037166430426667e-01, -2.6037166430426667e-01,
                                -9.6550846522825806e-01};
    auto problem = ioh::problem::cec2022::LevyFunction(1, 2);
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
