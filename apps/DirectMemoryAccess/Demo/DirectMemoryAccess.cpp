/*
 *  DirectMemoryAccess.cpp
 *  DMA
 *
 *  Created by vorg on 2009-10-06.
 *  Copyright 2009 Vorg. All rights reserved.
 *
 */

#include "DirectMemoryAccess.h"
#include "Utils.h"
#include "OS.h"
#include "Timer.h"
#include "MathLib.h"
#include "Effect.h"
#include "DistortedSphere.h"
#include "RaytracedTunnel.h"
#include "LutDistort.h"

using namespace flow;

//------------------------------------------------------------------------------

void DirectMemoryAccess::init() {
	Log::msg("DirectMemoryAccess::init");
	GLApp::init();
	
	bg = new LutDistort();	
	effect = new DistortedSphere();
}

//------------------------------------------------------------------------------

void DirectMemoryAccess::draw() {	
	GLApp::draw();
	if (Timer::getInstance().getTotalFrameCount() % 100 == 33) {
		Log::msg("draw %f", Timer::getInstance().getFPS());
	}				
	bg->draw();
	//effect->draw();
}

//------------------------------------------------------------------------------

void DirectMemoryAccess::dispose() {
	if (effect) {
		delete effect;
		effect = NULL;
	}
	if (bg) {
		delete bg;
		bg = NULL;
	}
}

//------------------------------------------------------------------------------

void DirectMemoryAccess::onMouseDown(int x, int y) {
	effect->onMouseDown(x, y);
	bg->onMouseDown(x, y);
}

//------------------------------------------------------------------------------

void DirectMemoryAccess::onMouseUp(int x, int y) {
	effect->onMouseUp(x, y);
	bg->onMouseUp(x, y);
}

//------------------------------------------------------------------------------

void DirectMemoryAccess::onMouseMove(int x, int y) {
	effect->onMouseMove(x, y);
	bg->onMouseMove(x, y);	
}

//------------------------------------------------------------------------------
