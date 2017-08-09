#ifndef MC_COMPLEX_H
#define	MC_COMPLEX_H

#include <iostream>
#include <string>
namespace mc {

    class complex {
        double _real, _imaginary;
    public:
        complex(const double& = 0, const double& = 0);
        complex(const complex&);
        ~complex();

        void operator +=(const complex&);
        void operator -=(const complex&);
        void operator *=(const complex&);
        void operator /=(const complex&);

        complex& operator =(const complex&);
        complex& operator =(const double&);

        const double& real() const;
        const double& imaginary() const;
        void swap(complex&);
        std::string toString() const;
        double module() const;
        double angle() const;
        complex conjugate() const;
    };

    complex operator +(const complex&, const complex&);
    complex operator -(const complex&, const complex&);
    complex operator *(const complex&, const complex&);
    complex operator /(const complex&, const complex&);

    std::ostream& operator <<(std::ostream&, const complex&);
    bool operator ==(const complex&, const complex&);

    complex pow(const complex&, const complex&);
    complex sqrt(const complex&);
    double abs(const complex&);
}


#endif	/* COMPLEX_H */

