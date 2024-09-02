#ifndef MYCOMPLEX_MYEXCEPTION_H_
#define MYCOMPLEX_MYEXCEPTION_H_

#include <exception>
#include <string>

class ComplexException : public std::exception {
public:
    explicit ComplexException( const std::string &msg ) : m_msg(msg) {}
    const char *what() const noexcept override { return m_msg.c_str(); }
private:
    std::string m_msg;
};

#endif  // MYCOMPLEX_MYEXCEPTION_H_
