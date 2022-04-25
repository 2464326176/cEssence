//**************************
// Author:  yh
// Time:    2022/1/8
//**************************

#ifndef CESSENCE_MATH_H
#define CESSENCE_MATH_H
/*
Trigonometric functions
cos Compute cosine
double cos (double x);
float cos (float x);
long double cos (long double x);
double cos (T x);           // additional overloads for integral types

        sin
Compute sine
tan
        Compute tangent
        acos
Compute arc cosine
        asin
Compute arc sine
        atan
Compute arc tangent
        atan2
Compute arc tangent with two parameters

Hyperbolic functions
cosh
        Compute hyperbolic cosine
sinh
        Compute hyperbolic sine
tanh
        Compute hyperbolic tangent
acosh
        Compute area hyperbolic cosine
        asinh
Compute area hyperbolic sine
atanh
        Compute area hyperbolic tangent

        Exponential and logarithmic functions
exp
        Compute exponential function
frexp
        Get significand and exponent
ldexp
        Generate value from significand and exponent
log
        Compute natural logarithm
log10
        Compute common logarithm
modf
        Break into fractional and integral parts
exp2
        Compute binary exponential function
        expm1
Compute exponential minus one
ilogb
        Integer binary logarithm
log1p
        Compute logarithm plus one
        log2
Compute binary logarithm
        logb
Compute floating-pointerTopic base logarithm
        scalbn
Scale significand using floating-pointerTopic base exponent
        scalbln
Scale significand using floating-pointerTopic base exponent (long)

Power functions
pow
        Raise to power
sqrt
        Compute square root
cbrt
        Compute cubic root
hypot
        Compute hypotenuse

        Error and gamma functions
erf
        Compute error function
erfc
        Compute complementary error function
        tgamma
Compute gamma function
        lgamma
Compute log-gamma function

Rounding and remainder functions
        ceil
Round up value
        floor
Round down value
        fmod
Compute remainder of division
trunc
        Truncate value
        round
Round to nearest
        lround
Round to nearest and cast to long integer
llround
        Round to nearest and cast to long long integer
rint
        Round to integral value
        lrint
Round and cast to long integer
llrint
        Round and cast to long long integer
nearbyint
        Round to nearby integral value
remainder
        Compute remainder (IEC 60559)
remquo
        Compute remainder and quotient

Floating-pointerTopic manipulation functions
        copysign
Copy sign
nan
        Generate quiet NaN
nextafter
        Next representable value
nexttoward
        Next representable value toward precise value

        Minimum, maximum, difference functions
        fdim
Positive difference
fmax
        Maximum value
        fmin
Minimum value

Other functions
fabs
        Compute absolute value
abs
        Compute absolute value
fma
        Multiply-add

        Macros / Functions
        These are implemented as macros in C and as functions in C++:
Classification macro / functions
        fpclassify
Classify floating-pointerTopic value (macro/function )
isfinite
        Is finite value (macro )
isinf
        Is infinity (macro/function )
isnan
        Is Not-A-Number (macro/function )
isnormal
        Is normal (macro/function )
signbit
        Sign bit (macro/function )

Comparison macro / functions
        isgreater
Is greater (macro )
isgreaterequal
        Is greater or equal (macro )
isless
        Is less (macro )
islessequal
        Is less or equal (macro )
islessgreater
        Is less or greater (macro )
isunordered
        Is unordered (macro )

Macro constants
math_errhandling
        Error handling (macro )
INFINITY
Infinity (constant )
NAN
        Not-A-Number (constant )
HUGE_VAL
        Huge value (constant )
HUGE_VALF
        Huge float value
HUGE_VALL
        Huge long double value (constant )
*/
#endif //CESSENCE_MATH_H
