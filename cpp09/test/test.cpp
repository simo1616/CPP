#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <string>
#include <climits>

bool CheckBisex(int annee) {
	
	if (!(annee % 4)) {
		if(!(annee % 100)) {
			if(!(annee % 400)) {
			
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

bool strCheckYear(std::string const& annee, int& out, int const d, int const m)
{
    char* end;
    errno = 0;

    long val = std::strtol(annee.c_str(), &end, 10);

    if (errno != 0 || *end != '\0' || val < 2009 || val > 2100)
        return false;

    out = static_cast<int>(val);
	if(m == 2) {
		if(!CheckBisex(out) && d > 28) return false;
		else if (CheckBisex(out) && d > 29) return false;
	}
	if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) return false;
    return true;
}

bool strCheckMounth(std::string const& m, int& out) {
	char *end;
	errno = 0;

	long val = std::strtol(m.c_str(), &end, 10);
	if(errno != 0 || *end != '\0' || val < 1 || val > 12)
		return false;
	out = static_cast<int>(val);
	return true;
}

bool strCheckDay(std::string const& day, int& out) {
	char *end;
	errno = 0;

	long val = std::strtol(day.c_str(), &end, 10);
	if(errno != 0 || *end != '\0' || val < 1 || val > 31)
		return false;
	out = static_cast<int>(val);
	return true;
}
