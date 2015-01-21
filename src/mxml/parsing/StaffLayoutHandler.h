//  Created by Alejandro Isaza on 2014-03-25.
//  Copyright (c) 2014 Venture Media Labs. All rights reserved.

#pragma once
#include <lxml/BaseRecursiveHandler.h>
#include <lxml/DoubleHandler.h>
#include <mxml/dom/Types.h>


namespace mxml {

/**
 Staff layout includes the vertical distance from the bottom line of the previous staff in this system to the top line
 of the staff specified by the number attribute. The optional number attribute refers to staff numbers within the part,
 from top to bottom on the system. A value of 1 is assumed if not present. When used in the defaults element, the
 values apply to all parts. This value is ignored for the first staff in a system.
 */
struct StaffLayout {
    StaffLayout() : number(1), staffDistance() {}

    int number;
    dom::tenths_t staffDistance;
};


class StaffLayoutHandler : public lxml::BaseRecursiveHandler<StaffLayout> {
public:
    void startElement(const lxml::QName& qname, const AttributeMap& attributes);
    RecursiveHandler* startSubElement(const lxml::QName& qname);
    void endSubElement(const lxml::QName& qname, lxml::RecursiveHandler* parser);
    
private:
    lxml::DoubleHandler _doubleHandler;
};

} // namespace mxml
