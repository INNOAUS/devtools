/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
#if !defined(BOOST_SPIRIT_CONJURE_AST_HPP)
#define BOOST_SPIRIT_CONJURE_AST_HPP

#include <boost/config/warning_disable.hpp>
#include <boost/variant/recursive_variant.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/fusion/include/io.hpp>
#include <boost/optional.hpp>
#include <list>

namespace client { namespace ast
{
    ///////////////////////////////////////////////////////////////////////////
    //  The AST
    ///////////////////////////////////////////////////////////////////////////
    struct tagged
    {
        int id; // Used to annotate the AST with the iterator position.
                // This id is used as a key to a map<int, Iterator>
                // (not really part of the AST.)
    };

    struct nil {};
    struct unary;
    struct function_call;
    struct expression;

    struct identifier : tagged
    {
        identifier(std::string const& name = "") : name(name) {}
        std::string name;
    };

    typedef boost::variant<
            nil
          , bool
          , unsigned int
          , identifier
          , boost::recursive_wrapper<unary>
          , boost::recursive_wrapper<function_call>
          , boost::recursive_wrapper<expression>
        >
    operand;

    enum optoken
    {
        // precedence 1
        op_comma,

        // precedence 2
        op_assign,
        op_plus_assign,
        op_minus_assign,
        op_times_assign,
        op_divide_assign,
        op_mod_assign,
        op_bit_and_assign,
        op_bit_xor_assign,
        op_bitor_assign,
        op_shift_left_assign,
        op_shift_right_assign,

        // precedence 3
        op_logical_or,

        // precedence 4
        op_logical_and,

        // precedence 5
        op_bit_or,

        // precedence 6
        op_bit_xor,

        // precedence 7
        op_bit_and,

        // precedence 8
        op_equal,
        op_not_equal,

        // precedence 9
        op_less,
        op_less_equal,
        op_greater,
        op_greater_equal,

        // precedence 10
        op_shift_left,
        op_shift_right,

        // precedence 11
        op_plus,
        op_minus,

        // precedence 12
        op_times,
        op_divide,
        op_mod,

        // precedence 13
        op_positive,
        op_negative,
        op_pre_incr,
        op_pre_decr,
        op_compl,
        op_not,

        // precedence 14
        op_post_incr,
        op_post_decr,
    };

    struct unary
    {
        optoken operator_;
        operand operand_;
    };

    struct operation
    {
        optoken operator_;
        operand operand_;
    };

    struct function_call
    {
        identifier function_name;
        std::list<expression> args;
    };

    struct expression
    {
        operand first;
        std::list<operation> rest;
    };

    struct assignment
    {
        identifier lhs;
        expression rhs;
    };

    struct variable_declaration
    {
        identifier lhs;
        boost::optional<expression> rhs;
    };

    struct if_statement;
    struct while_statement;
    struct statement_list;
    struct return_statement;

    typedef boost::variant<
            variable_declaration
          , assignment
          , boost::recursive_wrapper<if_statement>
          , boost::recursive_wrapper<while_statement>
          , boost::recursive_wrapper<return_statement>
          , boost::recursive_wrapper<statement_list>
        >
    statement;

    struct statement_list : std::list<statement> {};

    struct if_statement
    {
        expression condition;
        statement then;
        boost::optional<statement> else_;
    };

    struct while_statement
    {
        expression condition;
        statement body;
    };

    struct return_statement : tagged
    {
        boost::optional<expression> expr;
    };

    struct function
    {
        std::string return_type;
        identifier function_name;
        std::list<identifier> args;
        statement_list body;
    };

    typedef std::list<function> function_list;

    // print functions for debugging
    inline std::ostream& operator<<(std::ostream& out, nil)
    {
        out << "nil"; return out;
    }

    inline std::ostream& operator<<(std::ostream& out, identifier const& id)
    {
        out << id.name; return out;
    }
}}

BOOST_FUSION_ADAPT_STRUCT(
    client::ast::unary,
    (client::ast::optoken, operator_)
    (client::ast::operand, operand_)
)

BOOST_FUSION_ADAPT_STRUCT(
    client::ast::operation,
    (client::ast::optoken, operator_)
    (client::ast::operand, operand_)
)

BOOST_FUSION_ADAPT_STRUCT(
    client::ast::function_call,
    (client::ast::identifier, function_name)
    (std::list<client::ast::expression>, args)
)

BOOST_FUSION_ADAPT_STRUCT(
    client::ast::expression,
    (client::ast::operand, first)
    (std::list<client::ast::operation>, rest)
)

BOOST_FUSION_ADAPT_STRUCT(
    client::ast::variable_declaration,
    (client::ast::identifier, lhs)
    (boost::optional<client::ast::expression>, rhs)
)

BOOST_FUSION_ADAPT_STRUCT(
    client::ast::assignment,
    (client::ast::identifier, lhs)
    (client::ast::expression, rhs)
)

BOOST_FUSION_ADAPT_STRUCT(
    client::ast::if_statement,
    (client::ast::expression, condition)
    (client::ast::statement, then)
    (boost::optional<client::ast::statement>, else_)
)

BOOST_FUSION_ADAPT_STRUCT(
    client::ast::while_statement,
    (client::ast::expression, condition)
    (client::ast::statement, body)
)

BOOST_FUSION_ADAPT_STRUCT(
    client::ast::return_statement,
    (boost::optional<client::ast::expression>, expr)
)

BOOST_FUSION_ADAPT_STRUCT(
    client::ast::function,
    (std::string, return_type)
    (client::ast::identifier, function_name)
    (std::list<client::ast::identifier>, args)
    (client::ast::statement_list, body)
)

#endif
