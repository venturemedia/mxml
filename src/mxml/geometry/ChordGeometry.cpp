//  Created by Alejandro Isaza on 2014-05-05.
//  Copyright (c) 2014 Venture Media Labs. All rights reserved.

#include "ChordGeometry.h"
#include "FermataGeometry.h"

#include <mxml/Metrics.h>

namespace mxml {

const coord_t ChordGeometry::kStemVerticalOffset = 1;
const coord_t ChordGeometry::kAccidentalSpacing = 2;
const coord_t ChordGeometry::kArticulationSpacing = 1;
const coord_t ChordGeometry::kFermataSpacing = 11;
const coord_t ChordGeometry::kDotSpacing = 2;

ChordGeometry::ChordGeometry(const dom::Chord& chord)
: MeasureElementGeometry(),
  _chord(chord),
  _notes(),
  _stem()
{
    auto firstNote = chord.firstNote();
    if (firstNote)
        setStaff(firstNote->staff());
}

Rect ChordGeometry::notesFrame() const {
    bool first = true;
    Rect frame;
    for (const NoteGeometry* noteGeom : _notes) {
        if (first)
            frame = noteGeom->frame();
        else
            frame = join(frame, noteGeom->frame());
        first = false;
    }
    return frame;
}

void ChordGeometry::extendStem(coord_t coordinate) {
    if (!_stem)
        return;

    auto frame = _stem->frame();
    if (_stem->stemDirection() == dom::kStemUp) {
        auto dy = frame.min().y - coordinate;
        frame.origin.y -= dy;
        frame.size.height += dy;
    } else {
        auto dy = coordinate - frame.max().y;
        frame.size.height += dy;
    }

    _stem->setFrame(frame);
    setBounds(subGeometriesFrame());
}

} // namespace mxml
