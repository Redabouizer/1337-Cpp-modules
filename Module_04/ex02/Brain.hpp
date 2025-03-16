#pragma once

#include <iostream>
#include <string>

class Brain {
	private:
		std::string		ideas[100];
		unsigned int	size;
	public:
		Brain(void);
		Brain(const Brain& other);
		~Brain(void);

		Brain&				operator=(const Brain& other);
		void				addIdea(std::string idea);
		const std::string&	getIdea(unsigned int index) const;
};
