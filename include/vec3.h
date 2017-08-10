#ifndef _Vector_H_
#define _Vector_H_

#include <cmath>
#include <iostream>
#include <cassert>

/*!
 * This class represents a 3D vector, that might be used to represent points,
 * directions, vectors, colors, offset.
 */
template <class ValueType>
class Vector {

    public:
        // Aliases
        
        //typedef float ValueType;
        
        enum FieldType : int {X = 0, Y = 1, Z = 2,
                              R = 0, G = 1, B = 2};

        // 3D vector
        ValueType e[3];

        /*!
         * 3D vector constructor.
         *
         * @param e0_ Element 0
         * @param e1_ Element 1
         * @param e2_ Element 2
         */
        Vector(ValueType e0_ = 0, ValueType e1_ = 0, ValueType e2_ = 0)
            : e{e0_, e1_, e2_} { /* empty */ }

        /* ----------------------- Access Operators ------------------------- */

        /*!
         * Get x value.
         *
         * @return X value
         */
        inline ValueType x() const { return e[X]; }

        /*!
         * Get y value.
         *
         * @return Y value
         */
        inline ValueType y() const { return e[Y]; }

        /*!
         * Get z value.
         *
         * @return Z value
         */
        inline ValueType z() const { return e[Z]; }

        /*!
         * Get red value.
         *
         * @return Red value
         */
        inline ValueType r() const { return e[R]; }

        /*!
         * Get green value.
         *
         * @return Green value
         */
        inline ValueType g() const { return e[G]; }

        /*!
         * Get blue value.
         *
         * @return Blue value
         */
        inline ValueType b() const { return e[B]; }

        /*!
         * Indexed access operator (rhs).
         *
         * @param idx Index
         */
        inline ValueType operator[](size_t idx) const { return e[idx]; }

        /*!
         * Indexed access operator (lhs).
         *
         * @param Index
         */
        inline ValueType& operator[](size_t idx) { return e[idx]; }

        /* --------------------- Algebraic Operators ------------------------ */

        /*!
         * Unary '+'.
         */
        inline const Vector& operator+(void) const { return *this; }

        /*!
         * Unary '-'.
         */
        inline Vector operator-(void) const { return Vector(-e[X], -e[Y], -e[Z]); }

        /*!
         * TO COMMENT.
         */
        inline Vector& operator+=(const Vector&);

        /*!
         * TO COMMENT.
         */
        inline Vector& operator-=(const Vector&);

        /*!
         * TO COMMENT.
         */
        inline Vector& operator*=(const Vector&);

        /*!
         * TO COMMENT.
         */
        inline Vector& operator/=(const Vector&);

        /*!
         * TO COMMENT.
         */
        inline Vector& operator*=(const ValueType);

        /*!
         * TO COMMENT.
         */
        inline Vector& operator/=(const ValueType);

        /* ------------------------------------------------------------------ */

        /*!
         * Get vector length.
         *
         * @return Vector length
         */
        inline ValueType length(void) const {
            return sqrt(squaredLength());
        }

        /*!
         * Get vector length squared.
         *
         * @return Vector length squared
         */
        inline ValueType squaredLength(void) const {
            return (e[X]*e[X] + e[Y]*e[Y] + e[Z]*e[Z]);
        }

        /*!
         * Make this vector an unit vector.
         */
        inline void makeUnitVector(void);
};

typedef Vector<unsigned char> Pixel; 
typedef Vector<unsigned char> Color;
typedef Vector<float> Offset;
typedef Vector<float> Point3;
typedef Vector<float> Vec3;

#include "../src/vec3.inl"

#endif
