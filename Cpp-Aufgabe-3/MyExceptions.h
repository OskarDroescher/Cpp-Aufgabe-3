#include <string>

class InitException {
public:
	InitException(const std::string& className, const std::string& reason) : m_className(className), m_reason(reason) { }

	std::string getError() const {
		return "Klasse \"" + m_className + "\" konnte nicht initialisiert werden!\n"
			"Grund: " + m_reason;
	}

private:
	std::string m_className;
	std::string m_reason;
};
