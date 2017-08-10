/*!
 * TO COMMENT.
 */
template<class ValueType> 
inline std::istream& operator>>(std::istream& is, Vector<ValueType>& v) {
    is >> v.e[Vector<ValueType>::X] >> v.e[Vector<ValueType>::Y] >> v.e[Vector<ValueType>::Z];
    return is;
}

/*!
 * TO COMMENT.
 */
template<class ValueType> 
inline std::ostream& operator<<(std::ostream& os, const Vector<ValueType>& v) {
    os << "{ " << v.e[Vector<ValueType>::X] << " "
               << v.e[Vector<ValueType>::Y] << " "
               << v.e[Vector<ValueType>::Z] << " }";
    return os;
}

/*!
 * TO COMMENT.
 */
template<class ValueType>
inline Vector<ValueType> operator+(const Vector<ValueType>& v1, const Vector<ValueType>& v2) {
    return Vector<ValueType>(v1.e[Vector<ValueType>::X] + v2.e[Vector<ValueType>::X],
                v1.e[Vector<ValueType>::Y] + v2.e[Vector<ValueType>::Y],
                v1.e[Vector<ValueType>::Z] + v2.e[Vector<ValueType>::Z]);
}

/*!
 * TO COMMENT.
 */
template<class ValueType>
inline Vector<ValueType> operator-(const Vector<ValueType>& v1, const Vector<ValueType>& v2) {
    return Vector<ValueType>(v1.e[Vector<ValueType>::X] - v2.e[Vector<ValueType>::X],
                           v1.e[Vector<ValueType>::Y] - v2.e[Vector<ValueType>::Y],
                           v1.e[Vector<ValueType>::Z] - v2.e[Vector<ValueType>::Z]);
}

/*!
 * TO COMMENT.
 */
template<class ValueType>
inline Vector<ValueType> operator*(const Vector<ValueType>& v1, const Vector<ValueType>& v2) {
    return Vector<ValueType>(v1.e[Vector<ValueType>::X] * v2.e[Vector<ValueType>::X],
                           v1.e[Vector<ValueType>::Y] * v2.e[Vector<ValueType>::Y],
                           v1.e[Vector<ValueType>::Z] * v2.e[Vector<ValueType>::Z]);
}

/*!
 * TO COMMENT.
 */
template<class ValueType>
inline Vector<ValueType> operator/(const Vector<ValueType>& v1, const Vector<ValueType>& v2) {
    return Vector<ValueType>(v1.e[Vector<ValueType>::X] / v2.e[Vector<ValueType>::X],
                           v1.e[Vector<ValueType>::Y] / v2.e[Vector<ValueType>::Y],
                           v1.e[Vector<ValueType>::Z] / v2.e[Vector<ValueType>::Z]);
}

/*!
 * TO COMMENT.
 */
template<class ValueType> 
inline Vector<ValueType> operator*(const Vector<ValueType>& v, ValueType t) {
    return Vector<ValueType>(v.e[Vector<ValueType>::X] * t,
                           v.e[Vector<ValueType>::Y] * t,
                           v.e[Vector<ValueType>::Z] * t);
}

/*!
 * TO COMMENT.
 */
template<class ValueType> 
inline Vector<ValueType> operator*(ValueType t, const Vector<ValueType>& v) {
    return Vector<ValueType>( t * v.e[Vector<ValueType>::X] ,
                            t * v.e[Vector<ValueType>::Y] ,
                            t * v.e[Vector<ValueType>::Z]);
}

/*!
 * TO COMMENT.
 */
template<class ValueType> 
inline Vector<ValueType> operator/(const Vector<ValueType>& v, ValueType t) {
    return Vector<ValueType>(v.e[Vector<ValueType>::X] / t,
                           v.e[Vector<ValueType>::Y] / t,
                           v.e[Vector<ValueType>::Z] / t);
}

/*!
 * TO COMMENT.
 */
template<class ValueType>  
inline ValueType dot(const Vector<ValueType>& v1, const Vector<ValueType>& v2) {
    return (v1[Vector<ValueType>::X] * v2[Vector<ValueType>::X] +
            v1[Vector<ValueType>::Y] * v2[Vector<ValueType>::Y] +
            v1[Vector<ValueType>::Z] * v2[Vector<ValueType>::Z]);
}

/*!
 * TO COMMENT.
 */
template<class ValueType> 
inline Vector<ValueType> cross(const Vector<ValueType>& v1, const Vector<ValueType>& v2) {
    return Vector<ValueType>((v1[Vector<ValueType>::Y] * v2[Vector<ValueType>::Z] - v1[Vector<ValueType>::Z] * v2[Vector<ValueType>::Y]),
                           (v1[Vector<ValueType>::X] * v2[Vector<ValueType>::Z] - v1[Vector<ValueType>::Z] * v2[Vector<ValueType>::X]),
                           (v1[Vector<ValueType>::X] * v2[Vector<ValueType>::Y] - v1[Vector<ValueType>::Y] * v2[Vector<ValueType>::X]));
}

template<class ValueType> 
inline Vector<ValueType>& Vector<ValueType>::operator+=(const Vector<ValueType>& v) {
    e[Vector<ValueType>::X] += v.e[Vector<ValueType>::X];
    e[Vector<ValueType>::Y] += v.e[Vector<ValueType>::Y];
    e[Vector<ValueType>::Z] += v.e[Vector<ValueType>::Z];
    return *this;
}

template<class ValueType> 
inline Vector<ValueType>& Vector<ValueType>::operator-=(const Vector<ValueType>& v) {
    e[Vector<ValueType>::X] -= v.e[Vector<ValueType>::X];
    e[Vector<ValueType>::Y] -= v.e[Vector<ValueType>::Y];
    e[Vector<ValueType>::Z] -= v.e[Vector<ValueType>::Z];
    return *this;
}

template<class ValueType> 
inline Vector<ValueType>& Vector<ValueType>::operator*=(const Vector<ValueType>& v) {
    e[Vector<ValueType>::X] *= v.e[Vector<ValueType>::X];
    e[Vector<ValueType>::Y] *= v.e[Vector<ValueType>::Y];
    e[Vector<ValueType>::Z] *= v.e[Vector<ValueType>::Z];
    return *this;
}

template<class ValueType> 
inline Vector<ValueType>& Vector<ValueType>::operator/=(const Vector<ValueType>& v) {
    e[Vector<ValueType>::X] /= v.e[Vector<ValueType>::X];
    e[Vector<ValueType>::Y] /= v.e[Vector<ValueType>::Y];
    e[Vector<ValueType>::Z] /= v.e[Vector<ValueType>::Z];
    return *this;
}

template<class ValueType>
inline Vector<ValueType>& Vector<ValueType>::operator*=(const ValueType t) {
    e[Vector<ValueType>::X] *= t;
    e[Vector<ValueType>::Y] *= t;
    e[Vector<ValueType>::Z] *= t;
    return *this;
}

template<class ValueType>
inline Vector<ValueType>& Vector<ValueType>::operator/=(const ValueType t) {
    e[Vector<ValueType>::X] /= t;
    e[Vector<ValueType>::Y] /= t;
    e[Vector<ValueType>::Z] /= t;
    return *this;
}

/*!
 * TO COMMENT.
 */
template<class ValueType>
inline Vector<ValueType> unitVector(const Vector<ValueType>& v) {
    return v / v.length();
}

/*!
 * TO COMMENT.
 */
template<class ValueType> 
inline void Vector<ValueType>::makeUnitVector(void) {
    ValueType k = (1 / sqrt(dot(*this, *this)));
    e[Vector<ValueType>::X] *= k;
    e[Vector<ValueType>::Y] *= k;
    e[Vector<ValueType>::Z] *= k;
}
