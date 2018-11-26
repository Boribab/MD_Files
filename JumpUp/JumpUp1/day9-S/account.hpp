#include <map>
#include <string>

using std::map;
using std::string;

class AccountManager {
private:
	map<string, string> accounts;

public:
	std::string& GetAccount(const std::string&) const;
};