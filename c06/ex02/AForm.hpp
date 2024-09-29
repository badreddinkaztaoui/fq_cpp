/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:31:58 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/07/18 06:30:22 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
    const std::string _name;
    bool _signed;
    const int _signGrade;
    const int _execGrade;
public:
    AForm();
    AForm(std::string const name, int signGrade, int execGrade);
    AForm(AForm const & rhs);
    AForm & operator=(AForm const & rhs);
    virtual ~AForm();

    std::string getName() const;
    bool        getSigned() const;
    int         getSignGrade() const;
    int         getExecGrade() const;
    
    void        beSigned(Bureaucrat &bureaucrat);
    virtual void execute(Bureaucrat const & executor) const = 0;
    
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class FormNotSignedException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream    &operator<<(std::ostream &cout, const AForm &rhs);

#endif