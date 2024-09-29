/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:02:29 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/07/18 10:01:32 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main() {

    try {
        Form f("Internship", 40, 50);
        std::cout << f << std::endl;
        
        Bureaucrat b("Badreddin", 40);
        b.decrementGrade();
        b.incrementGrade();
        b.incrementGrade();
        b.incrementGrade();
        
        std::cout << b << std::endl;
        b.signForm(f);
        
        std::cout << f << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}