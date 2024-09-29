/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:09:32 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/07/18 05:48:51 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string const name, int grade): _name(name) {
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    } else if (grade > 150) {
        throw Bureaucrat::GtadeTooLowException();
    } else {
        _grade = grade;
    }
}

Bureaucrat::Bureaucrat(Bureaucrat const & rhs) : _name(rhs._name), _grade(rhs._grade) {}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs) {
    if (this != &rhs) {
        _grade = rhs._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void    Bureaucrat::incrementGrade() {
    if (_grade - 1 < 1) {
        throw Bureaucrat::GradeTooHighException();
    } else {
        _grade--;
    }
}

void    Bureaucrat::decrementGrade() {
    if (_grade + 1 > 150) {
        throw Bureaucrat::GtadeTooLowException();
    } else {
        _grade++;
    }
}

void    Bureaucrat::signForm(Form &form) {
    try {
        form.beSigned(*this);
        if (form.getSigned())
            std::cout << _name << " signs " << form.getName() << std::endl;
    } catch (std::exception & e) {
        std::cerr << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* Bureaucrat::GtadeTooLowException::what() const throw() {
    return "Grade is too low";
}

std::ostream    &operator<<(std::ostream & cout, Bureaucrat const & rhs) {
    cout << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return (cout);
}