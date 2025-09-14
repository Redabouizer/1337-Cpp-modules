#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreation",145,137), _target("default") {}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreation",145,137), _target(target) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &o) : AForm(o), _target(o._target) {}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &o) { if (this!=&o) _target=o._target; return *this; }
ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const {
    std::ofstream ofs((_target + "_shrubbery").c_str());
    if (!ofs) return;
    ofs << "      /\\n";
    ofs << "     /\\*\\n";
    ofs << "    /\\O*\\n";
    ofs << "   /\\*O*\\n";
    ofs << "  /\\O*O*\\n";
    ofs << " /\\*O*O*\\n";
    ofs << "/\\O*O*O*\\n";
    ofs << "      ||\n";
    ofs << "      ||\n";
    ofs.close();
}
