#ifndef DILI_LINEARREGRESSOR_H
#define DILI_LINEARREGRESSOR_H

#include <cstdint>
struct linearRegressor {
    double a;
    double b;
private:
    double _de_b;
    double _nu_b;
    double sum_x;

    uint64_t delta_x;


//    double sum_y;
public:
    linearRegressor(): a(0), b(0), _de_b(0), _nu_b(0), sum_x(0), delta_x(0) {}
    linearRegressor(linearRegressor *rhs): a(rhs->a), b(rhs->b), _de_b(rhs->_de_b), _nu_b(rhs->_nu_b), sum_x(rhs->sum_x), delta_x(rhs->delta_x) {}

//    void init(uint64_t *data, int fanout);
    void init(uint64_t *_data, int left_start_idx, int start_idx, int fanout);
    void init_w_sampling(uint64_t *_data, int left_start_idx, int start_idx, int fanout);
    void copy_from(linearRegressor *rhs);

    void merge_and_self_update(linearRegressor *rhs, int left_fan, int right_fan, uint64_t x_min);

    void merge(linearRegressor *lhs, linearRegressor *rhs, int left_fan, int right_fan, uint64_t x_min);
    void merge_w_sampling(linearRegressor *lhs, linearRegressor *rhs, int left_fan, int right_fan, uint64_t x_min);

    void cal_ab(int fanout, uint64_t x_min);
    void cal_ab_w_sampling(int fanout, uint64_t x_min);

    double cal_loss(uint64_t *data, int fanout);
    double cal_loss_w_sampling(uint64_t *data, int fanout);

    void print(uint64_t *data, int fanout);

    void set_delta_x(uint64_t dx) { delta_x = dx; }

    inline uint64_t get_delta_x() { return delta_x; }

private:
    void print_cal_ab(int fanout);
};


#endif // DILI_LINEARREGRESSOR_H
