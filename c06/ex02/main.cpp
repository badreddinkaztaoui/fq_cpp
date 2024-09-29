/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:02:29 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/07/18 06:32:52 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main() {
    
    try {
        Bureaucrat bureaucrat("Bureaucrat", 136);
        std::cout << bureaucrat << std::endl;

        ShrubberyCreationForm form("Home");
        bureaucrat.signForm(form);
        
        form.execute(bureaucrat);
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    } 
    
    return 0;
}