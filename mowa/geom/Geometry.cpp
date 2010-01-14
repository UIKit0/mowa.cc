/*
 *  Geometry.cpp
 *  DirectMemoryAccess
 *
 *  Created by Marcin Ignac on 1/3/10.
 *  Copyright 2010 marcinignac.com. All rights reserved.
 *
 */

#include "Geometry.h"
#include "VertexStream.h"
#include "MathLib.h"

namespace flow {
//------------------------------------------------------------------------------
	
void Geometry::invertNormals() {
	VertexAttrib* normAttrib = vertexStream.getAttrib("normal", TYPE_VEC3);
	vec3* normBuf = (vec3*)normAttrib->getBuffer();
	
	int numVertices = vertexStream.getNumVertices();
	for(int i=0; i<numVertices; i++, normBuf++) {
		*normBuf = -*normBuf;
	}
}
	
//------------------------------------------------------------------------------
}


