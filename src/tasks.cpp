#include <iostream>   // cout
#include <algorithm>  // copy, fill

#include "tasks.hpp"

// ИСПОЛЬЗОВАНИЕ ЛЮБЫХ ДРУГИХ БИБЛИОТЕК НЕ СОВЕТУЕТСЯ И МОЖЕТ ПОВЛИЯТЬ НА ВАШИ БАЛЛЫ

using std::cout;
using std::fill;
using std::copy;

// Задание 1
void swap_args(int *lhs, int *rhs) {
    if (lhs != nullptr && rhs != nullptr) {
        int value_saver = *lhs;
        *lhs = *rhs;
        *rhs = value_saver;
    }
}

// Задание 2
int **allocate_2d_array(int num_rows, int num_cols, int init_value) {
    if (num_cols < 1 || num_rows < 1) {
        return nullptr;
    }
    int **arr = new int *[num_rows];
    for (int i = 0; i < num_rows; i++) {
        arr[i] = new int[num_cols];
    }
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            arr[i][j] = init_value;
        }
    }
    return arr;
}

// Задание 3
bool copy_2d_array(int **arr_2d_source, int **arr_2d_target, int num_rows, int num_cols) {
    if (num_cols > 0 && num_rows > 0 && arr_2d_source != nullptr && arr_2d_target != nullptr) {
        for (int i = 0; i < num_rows; i++) {
            for (int j = 0; j < num_cols; j++) {
                arr_2d_target[i][j] = arr_2d_source[i][j];
            }
        }
        return true;
    }
    return false;
}

// Задание 4
void reverse_1d_array(vector<int> &arr) {
    for (int i = 0; i < arr.size() / 2; i++) {
        int value_saver = arr[i];
        arr[i] = arr[arr.size() - 1 - i];
        arr[arr.size() - 1 - i] = value_saver;
    }
}

// Задание 5
void reverse_1d_array(int *arr_begin, int *arr_end) {
    if (arr_begin != nullptr && arr_end != nullptr) {
        int value_saver;
        while (arr_begin <= arr_end) {
            value_saver = *arr_begin;
            *arr_begin = *arr_end;
            *arr_end = value_saver;
            ++arr_begin;
            --arr_end;
        }
    }
}

// Задание 6
int *find_max_element(int *arr, int size) {
    if (arr != nullptr && size > 0) {
        int *max = arr;
        int *element = arr;
        for (    int i = 1; i < size; i++) {
            element++;
            if (*max < *element) {
                max = element;
            }
        }
        return max;
    }
    return nullptr;
}

// Задание 7
vector<int> find_odd_numbers(vector<int> &arr) {
    if (arr.empty()) {
        return {};
    }
    vector<int> result;
    for (int element : arr) {
        if (element % 2 != 0) {
            result.push_back(element);
        }
    }
    return result;
}

// Задание 8
vector<int> find_common_elements(vector<int> &arr_a, vector<int> &arr_b) {
    if (arr_a.empty() || arr_b.empty()) {
        return {};
    }
    vector<int> result;
    bool flag = true;
    for (int & element_a : arr_a) {
        for (int element_b : arr_b) {
            if (element_a == element_b) {
                result.push_back(element_a);
            }
        }
    }
    return result;
}
