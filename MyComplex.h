#ifndef MYCOMPLEX_MYCOMPLEX_H_
#define MYCOMPLEX_MYCOMPLEX_H_

#include <iostream>
#include <ostream>

template<typename T>
class MyComplex
{
private:
    T _real;
    T _imag;

public:
    // Constuct
    MyComplex() = delete;
    explicit MyComplex( const T& real, const T& imag ) noexcept : _real(real), _imag(imag) {}
    MyComplex( const MyComplex& rhs ) noexcept : _real(rhs._real), _imag(rhs._imag) {}
    MyComplex( MyComplex&& rhs ) noexcept
    {
        this->_real = rhs._real;
        this->_imag = rhs._imag;
    }

    MyComplex& operator=( const MyComplex& rhs ) noexcept
    {
        if( *this != rhs )
        {
            this->_real = rhs._real;
            this->_imag = rhs._imag;
        }
        return *this;
    }

    MyComplex& operator=( MyComplex&& rhs ) noexcept
    {
        if( *this != rhs )
        {
            this->_real = rhs._real;
            this->_imag = rhs._imag;
        }
        return *this;
    }

    ~MyComplex() = default;

    // Base operations
    T Real() const noexcept { return this->_real; }
    T& Real() noexcept { return ( T& ) this->_real; }

    T Imag() const noexcept { return this->_imag; }
    T& Imag() noexcept { return ( T& ) this->_imag; }

    // Bool operations
    bool operator==( const MyComplex& rhs ) const noexcept
    {
        if( ( ( this->_real != rhs._real ) || ( this->_imag != rhs._imag ) ) )
            return false;
        return true;
    }

    bool operator!=( const MyComplex& rhs ) const noexcept { return !(*this == rhs); }
    

    // Math operations
    MyComplex& operator++() noexcept
    {
        ++_real;
        return *this;
    }
    
    MyComplex& operator--() noexcept
    {
        --_real;
        return *this;
    }
    
    MyComplex operator++(int) noexcept
    {
        MyComplex cp(*this);
        ++_real;
        return cp;
    }
    
    MyComplex operator--(int) noexcept
    {
        MyComplex cp(*this);
        --_real;
        return cp;
    }

    MyComplex& operator+=( const MyComplex& rhs ) noexcept
    {
        this->_real += rhs._real;
        this->_imag += rhs._imag;
        return *this;
    }

    MyComplex& operator-=( const MyComplex& rhs ) noexcept
    {
        this->_real -= rhs._real;
        this->_imag -= rhs._imag;
        return *this;
    }

    MyComplex operator-() noexcept { return MyComplex( -this->_real, -this->_imag ); }

    template<typename Tx>
    friend std::ostream& operator<<( std::ostream&, const MyComplex<Tx>& ) noexcept;
};

template<typename T>
std::ostream& operator<<( std::ostream& out, const MyComplex<T>& comp ) noexcept
{
    out << comp.Real() << ( ( comp.Imag() < 0 ) ? "" : " " ) << comp.Imag() << 'i';
    return out;
}

#endif  // MYCOMPLEX_MYCOMPLEX_H_
