/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:31:58 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/07/18 10:23:28 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
    const std::string _name;
    const int _signGrade;
    const int _execGrade;
    bool _signed;
public:
    Form();
    Form(std::string const name, int signGrade, int execGrade);
    Form(Form const & rhs);
    Form & operator=(Form const & rhs);
    ~Form();

    std::string getName() const;
    bool        getSigned() const;
    int         getSignGrade() const;
    int         getExecGrade() const;
    
    void        beSigned(Bureaucrat &bureaucrat);
    
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream    &operator<<(std::ostream &cout, const Form &rhs);

#endif