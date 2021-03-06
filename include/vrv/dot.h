/////////////////////////////////////////////////////////////////////////////
// Name:        dot.h
// Author:      Laurent Pugin
// Created:     2014
// Copyright (c) Authors and others. All rights reserved.
/////////////////////////////////////////////////////////////////////////////

#ifndef __VRV_DOT_H__
#define __VRV_DOT_H__

#include "layerelement.h"
#include "positioninterface.h"

namespace vrv {

class Note;

//----------------------------------------------------------------------------
// Dot
//----------------------------------------------------------------------------

class Dot : public LayerElement, public PositionInterface {
public:
    /**
     * @name Constructors, destructors, and other standard methods
     * Reset method resets all attribute classes
     */
    ///@{
    Dot();
    virtual ~Dot();
    virtual void Reset();
    virtual std::string GetClassName() const { return "Dot"; }
    virtual ClassId Is() const { return DOT; }
    ///@}

    virtual PositionInterface *GetPositionInterface() { return dynamic_cast<PositionInterface *>(this); }

    /** Override the method since alignment is required */
    virtual bool HasToBeAligned() const { return true; }

    //----------//
    // Functors //
    //----------//

    /**
     * See Object::PreparePointersByLayer
     */
    virtual int PreparePointersByLayer(FunctorParams *functorParams);

    /**
     * See Object::ResetDrawing
     */
    virtual int ResetDrawing(FunctorParams *functorParams);

private:
    //
public:
    /**
     * A pointer to the note the point relates to.
     */
    Note *m_drawingNote;

private:
};

} // namespace vrv

#endif
