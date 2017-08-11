#ifndef _RAY_H_
#define _RAY_H_

#include "vec3.h"

class Ray {

	private:
		// Ray origin
		point3 origin;
		// Ray direction
		vec3 direction;

	public:
		// Alias
		typedef float RealType;

		/**
		 * Ray constructor.
		 *
		 * @param origin_ Ray origin
		 * @param direction_ Ray direction
		 */
		Ray(point3 origin_ = point3(), vec3 direction_ = vec3()) :
			origin(origin_), direction(direction_) { /* Empty */ }

		/* ------------------------ Access Methods -------------------------- */

		/**
		 * Get ray direction.
		 *
		 * @return Ray direction
		 */
		inline vec3 get_direction(void) const { return direction; }

		/**
		 * Get ray origin.
		 *
		 * @return Ray origin
		 */
		inline vec3 get_origin(void) const { return origin; }

		/**
		 * TO COMMENT.
		 */
		point3 pointAt(RealType t_) const {
			return origin + t_ * direction;
		}
};

#endif
