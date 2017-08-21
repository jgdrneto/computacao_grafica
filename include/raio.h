#ifndef _RAIO_H_
#define _RAIO_H_

#include "vetor.h"

class Raio {

	private:
		// Ray origin
		Ponto3 origem;
		// Ray direction
		Vetor3 direcao;

	public:
		// Alias
		typedef float TipoReal;

		/**
		 * Ray constructor.
		 *
		 * @param origin_ Ray origin
		 * @param direction_ Ray direction
		 */
		Raio(Ponto3 nOrigem = Ponto3(), Vetor3 nDirecao = Vetor3()) :
			origem(nOrigem), direcao(nDirecao) { /* Empty */ }

		/* ------------------------ Access Methods -------------------------- */

		/**
		 * Get ray direction.
		 *
		 * @return Ray direction
		 */
		inline Vetor3 getDirecao(void) const { return this->direcao; }

		/**
		 * Get ray origin.
		 *
		 * @return Ray origin
		 */
		inline Vetor3 getOrigem(void) const { return this->origem; }

		/**
		 * TO COMMENT.
		 */
		Ponto3 apontar(TipoReal t) const {
			return this->origem + t * this->direcao;
		}
};

#endif
