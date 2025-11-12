#ifndef FRIEND_H
#define FRIEND_H

#include "device.h"

class FriendDevice {
public:
    void showDetails(const Device &d);
    void comparePower(const Device &d1, const Device &d2);
    double totalPower(const std::vector<Device*> &devices);
};

#endif
