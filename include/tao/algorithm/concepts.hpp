//! \file tao/algorithm/concepts.hpp
// Tao.Algorithm
//
// Copyright Fernando Pelliccioni 2016
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


#ifndef TAO_ALGORITHM_CONCEPTS_HPP
#define TAO_ALGORITHM_CONCEPTS_HPP

#define Integral typename

#define Iterator typename


    /*
        ForwardIterator(T) ^=
              Iterator(T)
            ^ regular_unary_function (successor)
    */
#define ForwardIterator typename     // EoP 6.6. Forward Iterators
            

#define BidirectionalIterator typename



#define Container typename

#define StrictWeakOrdering typename

#define Procedure typename
#define BinaryOperation typename
#define UnaryFunction typename

            

#endif /*TAO_ALGORITHM_CONCEPTS_HPP*/
