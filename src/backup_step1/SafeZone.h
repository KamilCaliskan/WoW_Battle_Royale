#ifndef SAFEZONE_H
#define SAFEZONE_H

class SafeZone {
public:
    int radius;

    SafeZone(int startRadius);
    void shrink();
};

#endif
