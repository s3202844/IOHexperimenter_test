#pragma once

#include "cec_basic_funcs.hpp"
#include "cec_utils.hpp"


namespace ioh::problem::cec
{
    void split_gx(std::vector<size_t> &Gnx,
                  std::vector<std::vector<double>> &Gx,
                  const std::vector<double> &Gp, const std::vector<double> &x,
                  const std::vector<int> &SS, int cf_num, int nx)
    {
        std::vector<double> y;
        int tmp = 0;
        for (int i = 0; i < cf_num - 1; i++)
        {
            Gnx.push_back(ceil(Gp.at(i) * nx));
            tmp += Gnx.at(i);
        }
        Gnx.push_back(nx - tmp);
        for (int i = 0; i < nx; i++)
        {
            y.push_back(x.at(SS.at(i) - 1));
        }
        int j = -1;
        for (int i = 0; i < nx; i++)
        {
            if (Gx.size() == 0 || Gx.at(j).size() >= Gnx.at(j))
            {
                std::vector<double> cache;
                Gx.push_back(cache);
                j += 1;
            }
            Gx.at(j).push_back(y.at(i));
        }
    }

    const double cec2022_hf01(std::vector<double> &x, const std::vector<double> &Os,
                        const std::vector<double> &Mr,
                        const std::vector<int> &SS, bool s_flag, bool r_flag,
                        int nx)
    {
        int cf_num = 3;
        std::vector<size_t> Gnx;
        std::vector<double> Gp = {0.4, 0.4, 0.2};
        std::vector<std::vector<double>> Gx;
        sr_func(x, Os, Mr, 1.0, s_flag, r_flag, nx);
        split_gx(Gnx, Gx, Gp, x, SS, cf_num, nx);
        double f1 = bent_cigar_func(Gx.at(0), Os, Mr, false, false, Gnx.at(0));
        double f2 = hgbat_func(Gx.at(1), Os, Mr, false, false, Gnx.at(1));
        double f3 = rastrigin_func(Gx.at(2), Os, Mr, false, false, Gnx.at(2));
        return f1 + f2 + f3;
    }

    // void cec2022_hf02(double *x, double *f, int nx, double *Os, double *Mr,
    //                   int *S, int s_flag, int r_flag)
    // {
    //     int i, tmp, cf_num = 6;
    //     double fit[6];
    //     int G[6], G_nx[6];
    //     double Gp[6] = {0.1, 0.2, 0.2, 0.2, 0.1, 0.2};

    //     tmp = 0;
    //     for (i = 0; i < cf_num - 1; i++)
    //     {
    //         G_nx[i] = ceil(Gp[i] * nx);
    //         tmp += G_nx[i];
    //     }
    //     G_nx[cf_num - 1] = nx - tmp;

    //     G[0] = 0;
    //     for (i = 1; i < cf_num; i++)
    //     {
    //         G[i] = G[i - 1] + G_nx[i - 1];
    //     }
    //     double *y = calloc(nx, sizeof(double));
    //     double *z = calloc(nx, sizeof(double));

    //     sr_func(x, z, nx, Os, Mr, 1.0, s_flag, r_flag,
    //             y); /* shift and rotate */

    //     for (i = 0; i < nx; i++)
    //     {
    //         y[i] = z[S[i] - 1];
    //     }

    //     i = 0;
    //     hgbat_func(&y[G[i]], &fit[i], G_nx[i], Os, Mr, 0, 0);
    //     i = 1;
    //     katsuura_func(&y[G[i]], &fit[i], G_nx[i], Os, Mr, 0, 0);
    //     i = 2;
    //     ackley_func(&y[G[i]], &fit[i], G_nx[i], Os, Mr, 0, 0);
    //     i = 3;
    //     rastrigin_func(&y[G[i]], &fit[i], G_nx[i], Os, Mr, 0, 0);
    //     i = 4;
    //     schwefel_func(&y[G[i]], &fit[i], G_nx[i], Os, Mr, 0, 0);
    //     i = 5;
    //     schaffer_F7_func(&y[G[i]], &fit[i], G_nx[i], Os, Mr, 0, 0, y);

    //     f[0] = 0.0;
    //     for (i = 0; i < cf_num; i++)
    //     {
    //         f[0] += fit[i];
    //     }

    //     free(y);
    //     free(z);
    // }
    // void cec2022_hf03(double *x, double *f, int nx, double *Os, double *Mr,
    //                   int *S, int s_flag, int r_flag)
    // {

    //     int i, tmp, cf_num = 5;
    //     double fit[5];
    //     int G[5], G_nx[5];
    //     double Gp[5] = {0.3, 0.2, 0.2, 0.1, 0.2};

    //     tmp = 0;
    //     for (i = 0; i < cf_num - 1; i++)
    //     {
    //         G_nx[i] = ceil(Gp[i] * nx);
    //         tmp += G_nx[i];
    //     }
    //     G_nx[cf_num - 1] = nx - tmp;

    //     G[0] = 0;
    //     for (i = 1; i < cf_num; i++)
    //     {
    //         G[i] = G[i - 1] + G_nx[i - 1];
    //     }
    //     double *y = calloc(nx, sizeof(double));
    //     double *z = calloc(nx, sizeof(double));

    //     sr_func(x, z, nx, Os, Mr, 1.0, s_flag, r_flag,
    //             y); /* shift and rotate */

    //     for (i = 0; i < nx; i++)
    //     {
    //         y[i] = z[S[i] - 1];
    //     }
    //     i = 0;
    //     katsuura_func(&y[G[i]], &fit[i], G_nx[i], Os, Mr, 0, 0);
    //     i = 1;
    //     happycat_func(&y[G[i]], &fit[i], G_nx[i], Os, Mr, 0, 0);
    //     i = 2;
    //     grie_rosen_func(&y[G[i]], &fit[i], G_nx[i], Os, Mr, 0, 0);
    //     i = 3;
    //     schwefel_func(&y[G[i]], &fit[i], G_nx[i], Os, Mr, 0, 0);
    //     i = 4;
    //     ackley_func(&y[G[i]], &fit[i], G_nx[i], Os, Mr, 0, 0);
    //     f[0] = 0.0;
    //     for (i = 0; i < cf_num; i++)
    //     {
    //         f[0] += fit[i];
    //     }

    //     free(z);
    //     free(y);
    // }

} // namespace ioh::problem::cec