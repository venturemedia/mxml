//  Created by Alejandro Isaza on 2014-03-25.
//  Copyright (c) 2014 Venture Media Labs. All rights reserved.

#pragma once
#include "Types.h"

namespace mxml {
namespace dom {

/**
 Margins, page sizes, and distances are all measured in tenths to keep MusicXML data in a consistent coordinate system
 as much as possible. The translation to absolute units is done with the scaling type, which specifies how many
 millimeters are equal to how many tenths. For a staff height of 7 mm, millimeters would be set to 7 while tenths is
 set to 40. The ability to set a formula rather than a single scaling factor helps avoid roundoff errors.
 */
struct Scaling {
    Scaling() : millimeters(7), tenths(40) {}

    millimeters_t millimeters;
    tenths_t tenths;
};

} // namespace dom
} // namespace mxml
