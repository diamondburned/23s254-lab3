#include "group_members.hpp"

#include <regex>

const auto groupMembersBlockRegex =
    std::regex(R"(## Group Members\n\s*(?:-.*\n?)*)");

const auto groupMemberRegex = std::regex(R"(-\s*(.*) <(.*)>)");

const std::optional<GroupMember>
GroupMembers::by_name(const std::string &name) const {
  for (GroupMember member : *this) {
    if (member.name == name) {
      return member;
    }
  }
  return {};
}

const std::optional<GroupMember>
GroupMembers::by_email(const std::string &email) const {
  for (GroupMember member : *this) {
    if (member.email == email) {
      return member;
    }
  }
  return {};
}

const GroupMembers GroupMembersParser::parse(const std::string &markdown) {
  std::smatch match;
  if (std::regex_search(markdown, match, groupMembersBlockRegex)) {
    GroupMembers groupMembers;
    std::string groupMembersBlock = match[0];
    std::sregex_iterator groupMemberIterator(
        groupMembersBlock.begin(), groupMembersBlock.end(), groupMemberRegex);
    std::sregex_iterator end;
    while (groupMemberIterator != end) {
      std::smatch groupMemberMatch = *groupMemberIterator;
      GroupMember groupMember;
      groupMember.name = groupMemberMatch[1];
      groupMember.email = groupMemberMatch[2];
      groupMembers.push_back(groupMember);
      groupMemberIterator++;
    }
    return groupMembers;
  }
  return {};
}

const GroupMembers GroupMembersParser::parse(const std::ifstream &file) {
  std::stringstream buf;
  buf << file.rdbuf();
  return parse(buf.str());
}
