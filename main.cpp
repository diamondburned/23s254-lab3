#include <fstream>
#include <iostream>
#include <regex>

#include "group_members.hpp"

int main() {
  std::ifstream readme("README.md");

  const auto members = GroupMembersParser::parse(readme);
  std::cout << "Found " << members.size() << " group member(s):"
            << "\n";
  for (const auto &member : members) {
    std::cout << "  " << member.name << " <" << member.email << ">"
              << "\n";
  }

  return 0;
}
