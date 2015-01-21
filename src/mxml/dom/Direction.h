//  Created by Alejandro Isaza on 2014-03-18.
//  Copyright (c) 2014 Venture Media Labs. All rights reserved.

#pragma once
#include "DirectionType.h"
#include "Node.h"
#include "Optional.h"
#include "Sound.h"
#include "Types.h"

namespace mxml {
namespace dom {

class Direction : public Node {
public:
    Direction() : _placement(absentOptional(kPlacementAbove)), _type(), _staff(1), _start(0), _offset() {}
    
    Optional<Placement> placement() const {
        return _placement;
    }
    void setPlacement(Optional<Placement> placement) {
        _placement = placement;
    }
    
    DirectionType* type() const {
        return _type.get();
    }
    void setType(std::unique_ptr<DirectionType>&& type) {
        _type = std::move(type);
    }
    
    Optional<int> staff() const {
        return _staff;
    }
    void setStaff(Optional<int> staff) {
        _staff = staff;
    }
    
    time_t start() const {
        return _start;
    }
    void setStart(time_t start) {
        _start = start;
    }
    
    const Optional<float>& offset() const {
        return _offset;
    }
    void setOffset(const Optional<float>& offset) {
        _offset = offset;
    }
    
    const std::unique_ptr<Sound>& sound() const {
        return _sound;
    }
    void setSound(std::unique_ptr<Sound> sound) {
        _sound = std::move(sound);
    }
    
private:
    Optional<Placement> _placement;
    std::unique_ptr<DirectionType> _type;
    Optional<int> _staff;
    time_t _start;
    Optional<float> _offset;
    std::unique_ptr<Sound> _sound;
};

} // namespace dom
} // namespace mxml
