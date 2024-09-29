/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:17:34 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/07/18 10:26:23 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {
    _target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137) {
    _target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &rhs) : AForm(rhs) {
    _target = rhs._target;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
    if (this != &rhs) {
        _target = rhs._target;
    }
    return *this;
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!getSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();
    std::string filename = _target + "_shrubbery";
    std::ofstream outfile;

    outfile.open(filename.c_str());

    if (!outfile.is_open()) {
        std::cout << "Error: could not open file" << std::endl;
        return;   
    }

    std::string tree = "";
    
    tree += "      \\ .   ._, |_  .,            \n";
    tree += "       `-._\\/  .  \\ /    |/_    \n";
    tree += "           \\  _\\, y | \\//      \n";
    tree += "     _\\_.___\\, \\/ -.\\||       \n";
    tree += "       `7-,--.`._||  / / ,        \n";
    tree += "       /'     `-. `./ / |/_.'     \n";
    tree += "                 |    |//         \n";
    tree += "                 |_    /          \n";
    tree += "                 |-   |           \n";
    tree += "                 |    |           \n";
    tree += "                 |    |           \n";
    tree += "      ----------/      \\-------- \n";
    
    outfile << tree << std::endl;
    outfile.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}