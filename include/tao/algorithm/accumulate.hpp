//! \file tao/algorithm/accumulate.hpp
// Tao.Algorithm
//
// Copyright Fernando Pelliccioni 2016
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef TAO_ALGORITHM_ACCUMULATE_HPP
#define TAO_ALGORITHM_ACCUMULATE_HPP

#include <algorithm>
#include <iterator>
#include <utility>

#include <tao/algorithm/concepts.hpp>
#include <tao/algorithm/type_attributes.hpp>

namespace tao { namespace algorithm
{


//Note: for_each_n was added in C++17

//Complexity: 
//      Runtime:
//          Amortized: O(n)
//          Exact:     ???
//      Space:
//          O(???)
template <Iterator I, Procedure Proc>
    // requires(Readable(I) &&
    //     Procedure(Proc) && Arity(Proc) == 1 &&
    //     ValueType(I) == InputType(Proc, 0))
std::pair<Proc, I> for_each_n(I f, DistanceType<I> n, Proc proc) {
    // Precondition: $\property{readable\_weak\_range}(f, n)$
    while (n != 0) {
        proc(*f);
        --n;
        ++f;
    }
    return {proc, f};
}


template <Iterator I, typename T, BinaryOperation Op>
// requires T == Domain(Op)
inline
T accumulate(I f, I l, T init, Op op) {   
    // return sum of init and all in [f, l), using op
    while (f != l) {
        init = op(init, *f);
        ++f;
    }
    return init;
}

template <Iterator I, typename T, BinaryOperation Op>
// requires T == Domain(Op)
inline
T accumulate_n(I f, DistanceType<I> n, T init, Op op) {   
    // return sum of init and all in [f, n), using op
    while (n != 0) {
        init = op(init, *f);
        --n;
        ++f;
    }
    return init;
}


template <Iterator I, typename T, BinaryOperation Op, UnaryFunction F>
// requires T == Domain(F)
//          Codomain(F) == Domain(Op))
inline
T accumulate(I f, I l, T init, Op op, F fun) {   
    // return sum of init and all in [f, l), using op and fun
    while (f != l) {
        init = op(init, fun(*f));
        ++f;
    }
    return init;
}

template <Iterator I, typename T, BinaryOperation Op, UnaryFunction F>
// requires T == Domain(F)
//          Codomain(F) == Domain(Op))
inline
T accumulate_n(I f, DistanceType<I> n, T init, Op op, F fun) {   
    // return sum of init and all in [f, n), using op and fun
    while (n != 0) {
        init = op(init, fun(*f));
        --n;
        ++f;
    }
    return init;
}


}} /*tao::algorithm*/

#endif /*TAO_ALGORITHM_ACCUMULATE_HPP*/
