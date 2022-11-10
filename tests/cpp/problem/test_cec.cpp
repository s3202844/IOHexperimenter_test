#include "../utils.hpp"

#include "ioh/problem/cec.hpp"

using namespace ioh::problem::cec;

TEST_F(BaseTest, loadOShiftData)
{
    std::vector<double> Os;
    std::string dataPath = "/usr/local/include/ioh/problem/cec/cec_data";
    loadOShiftData(&Os, dataPath, 2, 1, 2022);
    for (auto d : Os)
    {
        std::cout << d << " ";
    }
    std::cout << std::endl;
}

TEST_F(BaseTest, loadMatrixData)
{
    std::vector<double> Mr;
    std::string dataPath = "/usr/local/include/ioh/problem/cec/cec_data";
    loadMatrixData(&Mr, dataPath, 2, 1, 2022);
    for (auto d : Mr)
    {
        std::cout << d << " ";
    }
    std::cout << std::endl;
}


TEST_F(BaseTest, cec2022_01)
{
    std::ofstream file;
    file.open("/home/ian/cec_core/results/exp_data/F1.txt", std::ios::out);
    if (!file.is_open())
    {
        std::cout << "open failed" << std::endl;
    }

    auto problem = cec2022_01(1, 2);

    for (double x1 = -100.0; x1 <= 100.0; x1 += 0.5)
    {
        for (double x2 = -100.0; x2 <= 100.0; x2 += 0.5)
        {
            std::vector<double> x = {x1, x2};
            file << std::to_string(x1) << " " << std::to_string(x2) << " "
                 << std::to_string(problem(x)) << std::endl;
        }
    }
    file.close();
}
