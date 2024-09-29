/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:33:52 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/07/18 06:31:09 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _name("default"), _signGrade(1), _execGrade(1) {}

AForm::AForm(std::string const name, const int signGrade, const int execGrade): _name(name), _signGrade(signGrade), _execGrade(execGrade) {
    if (signGrade < 1 || execGrade < 1) {
        throw AForm::GradeTooHighException();
    } else if (signGrade > 150 || execGrade > 150) {
        throw AForm::GradeTooLowException();
    }
    _signed = false;
}

AForm::AForm(AForm const & rhs): _name(rhs._name), _signGrade(rhs._signGrade), _execGrade(rhs._execGrade) {
    _signed = rhs._signed;
}

AForm & AForm::operator=(AForm const & rhs) {
    if (this != &rhs) {
        _signed = rhs._signed;
    }
    return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const {
    return _name;
}

bool AForm::getSigned() const {
    return _signed;
}

int AForm::getSignGrade() const {
    return _signGrade;
}

int AForm::getExecGrade() const {
    return _execGrade;
}

void    AForm::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _signGrade) {
        throw AForm::GradeTooLowException();
    }
	_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char *AForm::FormNotSignedException::what() const throw() {
    return ("Form is not signed");
}

std::ostream &operator<<(std::ostream &os, const AForm &Aform)
{
	os << "AForm: " << Aform.getName() << std::endl;
    os << "Signed: " << (Aform.getSigned() ? "TRUE" : "FALSE")  << std::endl;
	os << "Sign Grade: " << Aform.getSignGrade() << std::endl;
	os << "Exec Grade: " << Aform.getExecGrade() << std::endl;
	return (os);
}