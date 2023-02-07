#include <fstream>
#include <optional>
#include <string>
#include <vector>

struct GroupMember {
  std::string name;
  std::string email;
};

struct GroupMembers : std::vector<GroupMember> {
  const std::optional<GroupMember> by_name(const std::string &name) const;
  const std::optional<GroupMember> by_email(const std::string &email) const;
};

struct GroupMembersParser {
  static const GroupMembers parse(const std::string &markdown);
  static const GroupMembers parse(const std::ifstream &file);
};
