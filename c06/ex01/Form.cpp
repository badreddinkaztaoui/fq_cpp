/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:33:52 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/07/18 10:19:11 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("default"), _signGrade(1), _execGrade(1), _signed(false) {}

Form::Form(std::string const name, const int signGrade, const int execGrade): _name(name), _signGrade(signGrade), _execGrade(execGrade), _signed(false) {
    if (signGrade < 1 || execGrade < 1) {
        throw Form::GradeTooHighException();
    } else if (signGrade > 150 || execGrade > 150) {
        throw Form::GradeTooLowException();
    }
}

Form::Form(Form const & rhs): _name(rhs._name), _signGrade(rhs._signGrade), _execGrade(rhs._execGrade) {
    _signed = rhs._signed;
}

Form & Form::operator=(Form const & rhs) {
    if (this != &rhs) {
        _signed = rhs._signed;
    }
    return *this;
}

Form::~Form() {}

std::string Form::getName() const {
    return _name;
}

bool Form::getSigned() const {
    return _signed;
}

int Form::getSignGrade() const {
    return _signGrade;
}

int Form::getExecGrade() const {
    return _execGrade;
}

void    Form::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _signGrade) {
        throw Form::GradeTooLowException();
    }
	_signed = true;
}


const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form: " << form.getName() << std::endl;
    os << "Signed: " << (form.getSigned() ? "TRUE" : "FALSE")  << std::endl;
	os << "Sign Grade: " << form.getSignGrade() << std::endl;
	os << "Exec Grade: " << form.getExecGrade() << std::endl;
	return (os);
}