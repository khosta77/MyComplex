#ifndef MYCOMPLEX_TEST_H_
#define MYCOMPLEX_TEST_H_

#include "MyComplex.h"
#include "myexception.h"

#include <sstream>

template<typename T>
void test()
{
    //// Test construct
    MyComplex<T> a( 10, 20 );
    MyComplex<T> b( 20, 10 );
    // Test +=, -=
    a += b;
    if( a != MyComplex<T>( 30, 30 ) )
        throw ComplexException("30 30");
    a -= b;
    if( a != MyComplex<T>( 10, 20 ) )
        throw ComplexException("10, 20");
    a -= b;
    if( a != MyComplex<T>( -10, 10 ) )
        throw ComplexException("-10, 10");
    // Test ++, --
    if( ++a != MyComplex<T>( -9, 10 ) )
        throw ComplexException("-9, 10");
    if( a++ != MyComplex<T>( -9, 10 ) )
        throw ComplexException("-9., 10");
    if( a != MyComplex<T>( -8, 10 ) )
        throw ComplexException("-8, 10");
    if( --a != MyComplex<T>( -9, 10 ) )
        throw ComplexException("-11, 10");
    if( a-- != MyComplex<T>( -9, 10 ) )
        throw ComplexException("-9., 10");
    if( a != MyComplex<T>( -10, 10 ) )
        throw ComplexException("-10, 10");
    // Test method Real/Imag
    MyComplex<T> d( 10, 20 );
    if( d.Real() != 10 )
        throw ComplexException("Real read");
    d.Real() = 15;
    if( d.Real() != 15 )
        throw ComplexException("Real write");
    if( d.Imag() != 20 )
        throw ComplexException("Imag read");
    d.Imag() = 25;
    if( d.Imag() != 25 )
        throw ComplexException("Imag write");

    // Test -
    MyComplex<T> e( 10, -20 );
    if( -e != MyComplex<T>( -10, 20 ) )
        throw ComplexException("-");
    if( e != MyComplex<T>( 10, -20 ) )
        throw ComplexException("nothing");
    e = -e;
    if( e != MyComplex<T>( -10, 20 ) )
        throw ComplexException("-2");

    // Test <<
    MyComplex<T> f( 5, 6 );
    std::stringstream ss1;
    ss1 << f;
    if(  ss1.str() != "5 6i" )
        throw ComplexException("No <<");
    MyComplex<T> g( 5, -6 );
    std::stringstream ss2;
    ss2 << g;
    if(  ss2.str() != "5-6i" )
        throw ComplexException("No <<");
}

#endif  // MYCOMPLEX_TEST_H_
